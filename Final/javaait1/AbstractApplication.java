class VegVendor
{
 String veg[];
 int price[]; 
 int currentV, currentP, q;//to store the state of transaction
 String name;
 VegUser vu;

 VegVendor(String n, VegUser ref)
 {
  name = n;
  vu = ref;
  veg = new String[5];
  price = new int[5];
  
  veg[0] = "tomato";
  veg[1] = "potato";
  veg[2] = "onion";
  veg[3] = "brinjal";
  veg[4] = "beans";

  price[0] = 20;
  price[1] = 15;
  price[2] = 18;
  price[3] = 40;
  price[4] = 45;

 }//VegVendor()

 int inquiry(String vname)
 {
  int i;
  for(i =0; i< veg.length; i++)
  {
   if(veg[i].equalsIgnoreCase(vname))
   {
     currentV = i;
     currentP = price[i];
     return currentP;
   }
  }//for
  currentV = -1;
  return currentV; //not found
 } 

 double discount()
 {
   double d = 0;
   q = vu.quantity();
   if(q > 1 && q <=5)
    d = currentP * 5.0 /100.0; 
   else if(q > 5 && q <=10)
    d = currentP * 10.0 /100.0; 
  
   currentP -= d;
   return d;
 }

 void sell()
 {
  System.out.println("Selling "+ q + " kg of " + veg[currentV] + " @ Rs " + currentP + " per kg to "+ name );
 }
}//VegVendor

abstract class VegUser
{
 String name;
 VegUser(String n)
 {
   name = n;
 }

 void purchase()
 {
  VegVendor vv = new VegVendor(name,this);
  double p = vv.inquiry("onion");
  if(p != -1)
  {
   double d = vv.discount();
   if(d != 0)
   {
    p = p - d;
    vv.sell();
   }
   else
    System.out.println("I didnt got any discount");
  }
  else
   System.out.println("veg of choice is not available");
 }
 
 abstract int quantity();
}

class HomeUser extends VegUser
{
 HomeUser(String x)
 {
   super(x);
 }
 int quantity()
 {
   //... logic
   System.out.println("quantity of HomeUser");
   return 2;
 }
}

class Resto extends VegUser
{
 Resto(String x)
 {
   super(x);
 }
 int quantity()
 {
   //... logic
   System.out.println("quantity of Resto");
   return 8;
 }

}//Resto

class MHall extends VegUser
{
 MHall(String x)
 {
   super(x);
 }
 int quantity()
 {
   //... logic
   System.out.println("quantity of MHall");
   return 15;
 }

}

class AbstractApplication
{
 public static void main(String args[])
 {
  HomeUser hu = new HomeUser("Vikas");
  hu.purchase();

  Resto ro= new Resto("EatGood");
  ro.purchase();

  MHall mh = new MHall("ComeOnce");
  mh.purchase();

 }
}