import java.util.*;

class charCount
{
public static void main(String[] args){
int n; String ans="";
Scanner sc = new Scanner(System.in);
System.out.println("enter number of frames");
n=sc.nextInt();
String data[] = new String[n];
for(int i=0;i<n;i++){
System.out.println("enter data bits");
data[i]=sc.next();
ans = ans+String.valueOf(data[i].length()+1);
ans=ans+data[i];
}
System.out.println("the data in frames is: "+ans);
System.out.println("enter received data");
int c=0; String recData;
recData=sc.next();
while(n!=0){
int l = Integer.parseInt(String.valueOf(recData.charAt(c)));
c++;
while(l>1){
System.out.print(recData.charAt(c));
c++;
l--;
}
System.out.print("\n");
n--;
}

}
}