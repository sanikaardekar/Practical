import java.io.*;
import java.net.*;
class udps{
public static void main(String[] args) throws Exception{
byte[] sData = new byte[1024];
byte[] rData = new byte[1024];
DatagramSocket ss = new DatagramSocket(9876);
while(true){
DatagramPacket rPacket = new DatagramPacket(rData, rData.length);
ss.receive(rPacket);
String[] m={"m","t","w","th","f","sat","sun"};
int i=(int)(Math.random()*m.length);
String msg=m[i];
sData = msg.getBytes();
InetAddress ipadd = rPacket.getAddress();
int port = rPacket.getPort();
DatagramPacket sPacket =new DatagramPacket(sData, sData.length, ipadd, port);
ss.send(sPacket);
}
}
}