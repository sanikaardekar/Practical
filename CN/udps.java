import java.io.*;
import java.net.*;

class udps 
{
    public static void main(String[] args) throws Exception
    {
        byte[] rData = new byte[1024];
        byte[] sData = new byte[1024];
        String msg;
        DatagramSocket ss =new DatagramSocket(9876);
        while(true)
        {
            DatagramPacket rPacket = new DatagramPacket(rData, rData.length);
            ss.receive(rPacket);
            String[] m = {"Sun", "Mon", "Tue", "Wed", "Thurs", "Fri", "Sat"};
            int i = (int) (Math.random() * m.length);
            msg = m[i];
            sData = msg.getBytes();
            InetAddress ipadd = rPacket.getAddress();
            int port = rPacket.getPort();
            DatagramPacket sPacket = new DatagramPacket(sData, sData.length, ipadd, port);
            ss.send(sPacket);
        }
    }    
}