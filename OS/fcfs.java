package OS;
import java.util.*;

class fcfs {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter no of processes");
        int n = sc.nextInt();
        int pid[] = new int[n];
        int ct[] = new int[n];
        int tt[] = new int[n];
        int wt[] = new int[n];
        int at[] = new int[n];
        int bt[] = new int[n];
        float awt = 0;
        float atat = 0;
        for (int i = 0; i < n; i++) {
            System.out.println("enter p " + (i + 1) + " arrival time: ");
            at[i] = sc.nextInt();
            System.out.println("enter p " + (i + 1) + " burst time: ");
            bt[i] = sc.nextInt();
            pid[i] = i + 1;
        }
        int temp, i;
        for (i = 0; i < n; i++) {
            for (int j = 0; j < (n - i - 1); j++) {//n-i-1
                if (at[j] > at[j + 1]) {
                    temp = at[j];           //swapping at , bt, pid
                    at[j] = at[j + 1];
                    at[j + 1] = temp;

                    temp = bt[j];     
                    bt[j] = bt[j + 1];
                    bt[j + 1] = temp;

                    temp = pid[j];
                    pid[j] = pid[j + 1];
                    pid[j + 1] = temp;
                }

            }
        }
        for (i = 0; i < n; i++) {
            if (i == 0) {
                ct[i] = bt[i] + at[i];
            } else {
                if (at[i] > ct[i - 1]) {      //at[i]>ct[i-1]
                    ct[i] = bt[i] + at[i];
                } else {
                    ct[i] = ct[i - 1] + bt[i];
                }
            }
            tt[i] = ct[i] - at[i];
            wt[i] = tt[i] - bt[i];
            awt += wt[i];
            atat += tt[i];
        }

        for (i = 0; i < n; i++) {
            System.out.println("process " + pid[i] + " completion time: " + ct[i] + " waiting time: " + wt[i]);

        }
        System.out.println("avg waiting time " + (awt / n));
        System.out.println("avg turn around time " + (atat / n));

    }
}
