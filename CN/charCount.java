import java.util.*;

public class charCount {
    public static void main(String[] args) {
        int n;
        String ans = "";
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of data frames: ");
        n = sc.nextInt();
        String data[] = new String[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Enter data: ");
            data[i] = sc.next();
            ans = ans + String.valueOf(data[i].length() + 1);//impp
            ans = ans + data[i];//imp
        }
        System.out.println("\n" + "Frames created: " + ans);
        System.out.println("\nReceiver side: ");
        System.out.print("Enter the received data: ");
        String rec_data;
        rec_data = sc.next();
        int c = 0;
        while (n != 0) {
            int l = Integer.parseInt(String.valueOf(rec_data.charAt(c)));//impp
            c++;
            while (l > 1) {
                System.out.print(rec_data.charAt(c));
                l--;
                c++;
            }
            System.out.print("\n");
            n--;
        }
    }
}