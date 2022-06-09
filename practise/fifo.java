import java.util.HashSet;
import java.util.Queue;
import java.util.LinkedList;

class fifo{
static int pageFaults(int incomingStream[],int n,int frames){
int pageFaults=0;
HashSet s = new HashSet<>(frames);
Queue queue=new LinkedList<>();
for(int i=0;i<n;i++){
if(s.size()<frames){
if(!s.contains(incomingStream[i])){
s.add(incomingStream[i]);
pageFaults++;
queue.add(incomingStream[i]);
}
}
else{
if(!s.contains(incomingStream[i])){
int val=(int)queue.peek();
queue.poll();
s.remove(val);
s.add(incomingStream[i]);
pageFaults++;
queue.add(incomingStream[i]);
}
}
System.out.print(incomingStream[i]+"\t");
System.out.println(queue+"\n");
}
return pageFaults;
}
public static void main(String[] args){
int incomingStream[]={ 7, 0, 1, 2, 0, 3, 0, 3 };
int len=incomingStream.length;
int frames=3;
int pageFaults=pageFaults(incomingStream,len,frames);
int hit =len-pageFaults;
System.out.println("page faults = "+pageFaults);
System.out.println("page fault ratio = "+(double) pageFaults/len);
System.out.println("page hits = "+hit);
System.out.println("page hit ratio = "+(double) hit/len);
}
}