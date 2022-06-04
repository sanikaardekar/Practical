import java.util.Scanner;

public class priority {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of process : ");
        int n = input.nextInt();
        int[] id = new int[n];
        int[] AT = new int[n];
        int[] BT = new int[n];
        int[] CT = new int[n];
        int[] TT = new int[n];
        int[] WT = new int[n];
        int[] prior = new int[n + 1];
        float avgTAT = 0;
        float avgWT = 0;
        int end;
        int sum = 0;
        int i, j, smallest, count = 0, time;
        int[] x = new int[n]; // x
        for (i = 0; i < n; i++) {
            System.out.print("Enter the Process Id for P[" + (i + 1) + "]:");
            id[i] = input.nextInt();
            System.out.print("Enter the Arrival time for P[" + (i + 1) + "] : ");
            AT[i] = input.nextInt();
            System.out.print("Enter the Burst time for P[" + (i + 1) + "]:");
            BT[i] = input.nextInt();
            System.out.print("Enter the Priority for P[" + (i + 1) + "] :");
            prior[i] = input.nextInt();
        }
        int temp, temp1, temp2, temp3;
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (AT[i] > AT[j]) {
                    temp = AT[i]; // at bt prior id
                    AT[i] = AT[j];
                    AT[j] = temp;

                    temp1 = prior[i];
                    prior[i] = prior[j];
                    prior[j] = temp1;

                    temp2 = BT[i];
                    BT[i] = BT[j];
                    BT[j] = temp2;

                    temp3 = id[i];
                    id[i] = id[j];
                    id[j] = temp3;
                }
            }
        }
        for (i = 0; i < n; i++) {
            x[i] = BT[i];
        }
        prior[n] = 10000;

        
        for (time = 0; count != n; time++) {
            smallest = n;
            for (i = 0; i < n; i++) {
                if (AT[i] <= time && prior[i] < prior[smallest] && BT[i] > 0)
                    smallest = i;
            }
            BT[smallest]--;
            if (BT[smallest] == 0) {
                count++;
                end = time + 1;
                CT[smallest] = end;
                WT[smallest] = end - AT[smallest] - x[smallest];
                TT[smallest] = end - AT[smallest];
            }
        }
        for (i = 0; i < n; i++) {
            avgTAT += TT[i];
            avgWT += WT[i];
        }
        System.out.println("ID\tAT\tBT\tCT\tTAT\tWT\tPriority");
        for (i = 0; i < n; i++) {
            System.out.print(id[i] + "\t" + AT[i] + "\t" + x[i] + "\t" + CT[i]
                    + "\t" + TT[i] + "\t" + WT[i] + "\t" + prior[i]);
            System.out.println();
        }
        System.out.println("AVG TAT : " + avgTAT / n);
        System.out.println("AVG WT : " + avgWT / n);
    }
}