class Fuel
{
 private String fuelName;
 private double fuelPrice;

 Fuel(String s, double d)
 {
   fuelName = s;
   fuelPrice = d;
 }
 
 public void setFuelPrice(double fp) // setter or mutator methods
 {
   fuelPrice = fp;
 }

 public double getFuelPrice() //getter or accessor method
 {
   return fuelPrice;
 }

 public String getFuelName() //getter or accessor method
 {
   return fuelName;
 }

}//Fuel

class FuelTank
{
  private Fuel f;
  private double qty;

  FuelTank(String fn, double fp, double q)
  {
    f = new Fuel(fn,fp);
    qty = q;
  }

  void addFuel(double d)
  {
    qty += d;
  }

  void removeFuel(double d)
  {
    qty -= d;
  }

  public double getQuantity()
  {
    return qty;
  }  

  public Fuel getFuel()
  {
    return f;
  }

}//FuelTank


class FuelStation
{
 FuelTank arr[];
 
 FuelStation()
 {
  arr = new FuelTank[3];
  arr[0] = new FuelTank("Petrol", 82, 10000);
  arr[1] = new FuelTank("Diesel", 62, 20000);
  arr[2] = new FuelTank("CNG", 42, 5000);
 }//FuelStation

 int search(String fname)
 {
  int i;
  String fuelName;
  for(i =0 ; i< arr.length; i++)
  {
   fuelName = arr[i].getFuel().getFuelName();
   if(fname.equalsIgnoreCase(fuelName))
     return i; 
  }//for
  return -1; //not found
 }
 

 void sell(FuelUser fu)
 {
  String fn = fu.whichFuel();//runtime bound
  int tankIndex = search(fn);
  if(tankIndex != -1)
  {
    double rQ = fu.howMuchQty();//runtime bound
    double aQ = arr[tankIndex].getQuantity(); 
    if(rQ < aQ)
    {
      arr[tankIndex].removeFuel(rQ);
      double billAmt;
      billAmt = arr[tankIndex].getFuel().getFuelPrice() * rQ;
      System.out.println("======================");
      System.out.println("Thank You for purchasing " + rQ + " liters of " + fn);
      System.out.println("Bill Amout : Rs " + billAmt);
      System.out.println("Drive Safe");
      System.out.println("======================");
    } 
    else
      System.out.println("Sorry "+ rQ + "ltrs of " + fn + " is not available");

  }
  else
    System.out.println("Sorry we dont sell : " + fn);  
 }
}

interface FuelUser
{
  String whichFuel(); 
  double howMuchQty();
}

class Car implements FuelUser
{
 String fname;

 Car(String s)
 {
  fname = s;
 }

 void purchaseFuel(FuelStation fs)
 {
   fs.sell(this);
 } 

 public String whichFuel()
 {
   return fname;
 } 

 public double howMuchQty()
 {
   //...logic here
   return 10;
 }
}//Car

class Bike implements FuelUser
{
 void purchaseFuel(FuelStation fs)
 {
   fs.sell(this);
 } 

 public String whichFuel()
 {
   return "PETROL";
 } 

 public double howMuchQty()
 {
   //...logic here
   return 3;
 }
}//Bike


class FuelProject
{
 public static void main(String args[])
 {
  FuelStation fs = new FuelStation();
  Car c1 = new Car("petrol");
  Car c2 = new Car("diesel");
  Bike b = new Bike();
  
  c1.purchaseFuel(fs);
  c2.purchaseFuel(fs);
  b.purchaseFuel(fs);
 }
}