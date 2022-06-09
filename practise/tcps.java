import java.io.*;
import java.net.*;

class tcps{
public static void main(String[] args) throws Exception{
String msg;
ServerSocket ss = new ServerSocket(80);
while(true){
Socket s1 = ss.accept();
String[] m ={"sat","sun","mon","tue","wed","thu","fri"};
int i=(int)(Math.random()*m.length);
msg=m[i];
PrintStream pr = new PrintStream(s1.getOutputStream());
pr.println(msg);
}

}
}