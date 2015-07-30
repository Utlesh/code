import java.applet.*;
import java.util.Date;
import java.awt.*;

public class AppDemo extends Applet
{
 String msg;
 
 public void init()
 {
   msg = "Date : ";
   setBackground(Color.YELLOW);
   setForeground(Color.RED);
   Font f = new Font("Comic Sans MS", Font.BOLD, 40); //name, style, size
   setFont(f);
 }

 public void start()
 {
   Date d = new Date(System.currentTimeMillis());
   msg = msg + d.toString();
 }

 //for applet output rendering override paint
 //Formal Parameter Graphics reference g becomes a handle to applets output rendering pen
 public void paint(Graphics g)
 {
  g.drawString(msg, 100, 50); //drawString(string, x, y);
 }
}