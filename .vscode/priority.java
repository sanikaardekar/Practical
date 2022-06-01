import java.util.Scanner;
import java.util.Arrays;
public class priority
{
public static void main (String[]args)
{
Scanner input = new Scanner (System.in);
System.out.print("Enter the number of process : ");
int process = input.nextInt ();
int[] id = new int[process];
int[] AT = new int[process];
int[] BT = new int[process];
int[] CT = new int[process];
int[] TT = new int[process];
int[] WT = new int[process];
int[] prior = new int[process + 1];
float avgTAT = 0;
float avgWT = 0;
int end;
int sum = 0;
int i, j, smallest, count = 0, time;
int[] x = new int[process];
for (i = 0 ; i < process ; i ++)
{
System.out.print("Enter the Process Id for P[" + (i+1)+"]:");
id[i] = input.nextInt();
System.out.print("Enter the Arrival time for P["+ (i+1)+"] : ");
AT[i] = input.nextInt();
System.out.print("Enter the Burst time for P["+ (i+1)+"]:");
BT[i] = input.nextInt();
System.out.print("Enter the Priority for P[" + (i+1)+"] :");
prior[i] = input.nextInt();
}
int temp, temp1, temp2, temp3; 
for (i = 0; i < process; i++)
{
for (j = i + 1; j < process; j++)
{
if(AT[i] > AT[j])
{
temp = AT[i];
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
for (i = 0; i < process; i++)
{
x[i] = BT[i];
}
prior[process] = 10000;
for (time = 0; count != process; time++)
{
smallest = process;
for (i = 0; i < process; i++)
{
if (AT[i] <= time && prior[i] < prior[smallest] && BT[i] > 0)
smallest = i;
}
BT[smallest]--;
if (BT[smallest] == 0)
{
count++;
end = time + 1;
CT[smallest] = end;
WT[smallest] = end - AT[smallest] - x[smallest];
TT[smallest] = end - AT[smallest];
}
}
for (i = 0; i < process; i++)
{
avgTAT += TT[i];
avgWT += WT[i];
}
System.out.println ("ID\tAT\tBT\tCT\tTAT\tWT\tPriority");
for (i = 0; i < process; i++)
{
System.out.print (id[i] + "\t" + AT[i] + "\t" + x[i] + "\t" + CT[i]
+"\t" + TT[i] + "\t" + WT[i] + "\t" + prior[i]);
System.out.println ();
}
System.out.println ("AVG TAT : " + avgTAT/process);
System.out.println ("AVG WT : " + avgWT/process);
}
}