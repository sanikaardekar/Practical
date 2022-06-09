import java.util.*;

class priority{
public static void main(String[] args){
Scanner sc = new Scanner(System.in);
int n;
System.out.println("enter the number of processes");
n=sc.nextInt();
int at[]=new int[n];
int bt[]=new int[n];
int tt[]=new int[n];
int wt[]=new int[n];
int ct[]=new int[n];
int prior[]=new int[n+1];
int x[]=new int[n];
float awt=0,att=0;
int count=0,end,smallest,time,temp;

for(int i=0;i<n;i++){
System.out.print("enter arrival time");
at[i]=sc.nextInt();
System.out.print("enter burst time");
bt[i]=sc.nextInt();
System.out.print("enter priority");
prior[i]=sc.nextInt();
}
for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++){
if(at[i]>at[j]){
temp=at[i];
at[i]=at[j];
at[j]=temp;

temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;

temp=prior[i];
prior[i]=prior[j];
prior[j]=temp;
}
}
}

for(int i=0;i<n;i++){
x[i]=bt[i];
}
prior[n]=10000;
for(time=0;count!=n;time++){
smallest=n;
for(int i=0;i<n;i++){
if(at[i]<=time && bt[i]>0 && prior[i]<prior[smallest]){
smallest=i;
}
}
bt[smallest]--;
if(bt[smallest]==0){
count++;
end=time+1;
ct[smallest]=end;
wt[smallest]=end-at[smallest]-x[smallest];
tt[smallest]=end-at[smallest];
}
}
for(int i=0;i<n;i++){
awt=awt+wt[i];
att=att+tt[i];
}
System.out.println("process\tCT\tWT\tTAT");
for(int i=0;i<n;i++){
System.out.println(i+"\t"+ct[i]+"\t"+wt[i]+"\t"+tt[i]);
}
System.out.println("avg waiting time"+(awt/n));
System.out.println("avg turnaround time"+(att/n));

}
}