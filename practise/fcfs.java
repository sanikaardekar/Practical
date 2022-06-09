import java.util.*;

class fcfs{
public static void main(String[] args){
Scanner sc=new Scanner(System.in);
int n;
System.out.println("enter number of processes");
n=sc.nextInt();
int at[]=new int[n];
int bt[]=new int[n];
int wt[]=new int[n];
int tt[]=new int[n];
int ct[]=new int[n];
int pid[]=new int[n];

float awt=0,att=0;
for(int i=0;i<n;i++){
System.out.println("enter process "+(i+1)+"arrival time");
at[i]=sc.nextInt();
System.out.println("enter process "+(i+1)+"burst time");
bt[i]=sc.nextInt();
}
int temp;
for(int i=0;i<n;i++){
for(int j=0;j<(n-i-1);j++){
if(at[j]>at[j+1]){
temp=at[j];
at[j]=at[j+1];
at[j+1]=temp;

temp=bt[j];
bt[j]=bt[j+1];
bt[j+1]=temp;

temp=pid[j];
pid[j]=pid[j+1];
pid[j+1]=temp;
}
}
}

for(int i=0;i<n;i++){
if(i==0){
ct[i]=at[i]+bt[i];
}
else{
if(at[i]>ct[i-1]){
ct[i]=at[i]+bt[i];
}
else{
ct[i]=bt[i]+ct[i-1];
}
}
tt[i]=ct[i]-at[i];
wt[i]=tt[i]-bt[i];
awt=awt+wt[i];
att=att+tt[i];
}

for(int i=0;i<n;i++){
System.out.println("process "+(i+1)+" completion time "+ct[i]+" waiting time "+wt[i]);
}
System.out.println("awg waiting time "+awt/n);
System.out.println("awg turnaround time "+att/n);
}
}