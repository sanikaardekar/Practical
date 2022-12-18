import java.io.*;
import java.net.*;

public class client2 {

    public static void main(String a[]) throws Exception {
        InetAddress lclhost;
        lclhost = InetAddress.getLocalHost();
        Client client = new Client(lclhost);

        // Sending data to client 2
        client.setSendPort(9003); // recport=8002
        client.setRecPort(8002); // senport=9003
        client.recData();
        client.sendData();
        client.recData();

    }
}

class Client {

    InetAddress lclhost;
    int sendPort, recPort;

    Client(InetAddress lclhost) {
        this.lclhost = lclhost;
    }

    public void setSendPort(int sendPort) {
        this.sendPort = sendPort;
    }

    public void setRecPort(int recPort) {
        this.recPort = recPort;
    }

    public void sendData() throws Exception {
        BufferedReader br;
        DatagramSocket ds;
        DatagramPacket dp;
        String data = "";
        System.out.println("Enter the Response 'VOTE_COMMIT' || 'VOTE_ABORT' ");
        br = new BufferedReader(new InputStreamReader(System.in));

        data = br.readLine();
        System.out.println("Data is " + data);

        ds = new DatagramSocket(sendPort);
        dp = new DatagramPacket(data.getBytes(), data.length(), lclhost, sendPort - 1000);
        ds.send(dp);
        ds.close();

    }

    public void recData() throws Exception {
        byte buf[] = new byte[256];
        DatagramPacket dp;
        DatagramSocket ds;
        ds = new DatagramSocket(recPort);
        dp = new DatagramPacket(buf, buf.length);
        ds.receive(dp);
        ds.close();
        String msgStr = new String(dp.getData(), 0, dp.getLength());

        System.out.println(msgStr);
    }

};
