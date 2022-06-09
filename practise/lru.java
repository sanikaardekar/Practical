import java.util.HashSet;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;
class lru{
static void lru(){
Scanner sc = new Scanner(System.in);
int pageFaults=0, frames,hits=0;
int arr[]={7,0,1,2,0,3,0,4,2,3,0,3,1,2,0};
int n=arr.length;
HashSet<Integer> s= new HashSet<>(n);
HashMap<Integer,Integer> index =new HashMap<>();
System.out.println("enter frame size");
frames=sc.nextInt();
for(int i=0;i<n;i++){
if(s.size()<frames){
if(!s.contains(arr[i]))
{
s.add(arr[i]);
pageFaults++;
}
index.put(arr[i],i);
}
else{
int lru=Integer.MAX_VALUE; int val=Integer.MIN_VALUE;
Iterator<Integer> itr=s.iterator();
while(itr.hasNext()){
int temp=itr.next();
if(index.get(temp)<lru){
lru=index.get(temp);
val=temp;
}
}
if(!s.contains(arr[i])){
s.add(arr[i]);
pageFaults++;
}
s.remove(val);
s.add(arr[i]);
index.put(arr[i],i);
}
}
System.out.println("page faults "+pageFaults);
System.out.println("page hits "+(n-pageFaults));

}
public static void main(String[] args){
lru pra = new lru();
pra.lru();
}
}