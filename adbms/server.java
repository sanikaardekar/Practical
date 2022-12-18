import java.io.*;
import java.net.*;

public class server {

    public static void main(String a[]) throws Exception {
        BufferedReader br;
        InetAddress lclhost;
        lclhost = InetAddress.getLocalHost();
        TCPServer ser = new TCPServer(lclhost);

        System.out.println("Server in sending mode....");

        // Sending data to client 1
        ser.setSendPort(9000); // recport=8000
        ser.setRecPort(8001); // sendport=9001

        System.out.println("Send request data to client1..");
        br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        System.out.println("Data is " + s);
        ser.sendData();
        System.out.println("Waiting for response from client1...");
        ser.recData();

        // Sending data to client 2
        ser.setSendPort(9002); // recport=8002
        ser.setRecPort(8003); // senport=9003
        System.out.println("Send request data to client2..");
        br = new BufferedReader(new InputStreamReader(System.in));
        String s1 = br.readLine();
        System.out.println("Data is " + s1);
        ser.sendData();
        System.out.println("Waiting for response from client2.");
        ser.recData();

        // Sending the final result to client 1
        ser.setSendPort(9000);
        ser.sendData();

        // Sending the final result to client 2
        ser.setSendPort(9002);
        ser.sendData();
    }
}

class TCPServer {

    InetAddress lclhost;
    int sendPort, recPort;
    int ssend = 0;
    int scounter = 0;

    TCPServer(InetAddress lclhost) {
        this.lclhost = lclhost;
    }

    public void setSendPort(int sendPort) {
        this.sendPort = sendPort;
    }

    public void setRecPort(int recPort) {
        this.recPort = recPort;
    }

    public void sendData() throws Exception {

        DatagramSocket ds;
        DatagramPacket dp;
        String data = "";

        if (scounter < 2 && ssend < 2) {
            data = "VOTE_REQUEST";
        }

        if (scounter < 2 && ssend > 1) {
            data = "GLOBAL_ABORT";
            data = data + " TRANSACTION ABORTED";

        }
        if (scounter == 2 && ssend > 1) {
            data = "GLOBAL_COMMIT";
            data = data + " TRANSACTION COMMITED";

        }

        ds = new DatagramSocket(sendPort);
        dp = new DatagramPacket(data.getBytes(), data.length(), lclhost, sendPort - 1000);
        ds.send(dp);
        ds.close();
        ssend++;
    }

    public void recData() throws Exception {
        byte buf[] = new byte[256];
        DatagramPacket dp = null;
        DatagramSocket ds = null;
        String msgStr = "";
        try {
            ds = new DatagramSocket(recPort);
            dp = new DatagramPacket(buf, buf.length);
            ds.receive(dp);
            ds.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        msgStr = new String(dp.getData(), 0, dp.getLength());
        System.out.println("String = " + msgStr);
        if (msgStr.equalsIgnoreCase("VOTE_COMMIT")) {
            scounter++;
        }
        System.out.println("Counter value = " + scounter + "n Send value = " + ssend);
    }

};