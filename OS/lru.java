import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;

 
public class lru
{
  private void lru () 
  {
    int fsize = 0, page_faults = 0, page_hits = 0, n = 15;
    Scanner sc = new Scanner (System.in);
    
 
HashSet < Integer > s = new HashSet <> (n);
    
HashMap < Integer, Integer > index = new HashMap <> ();
    int arr[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 1, 2, 0 };
    
System.out.println ("Enter the size of frame = ");
    fsize = sc.nextInt ();
    
for (int i = 0; i < n; i++)
      
      {
	if (s.size () < fsize)
	  
	  {
	    if (!s.contains (arr[i]))
	      {
		
s.add (arr[i]);
		page_faults++;
	      
}
	    else
	      {
		
page_hits++;
	      
}
	    
index.put (arr[i], i);
	  
}
	else
	  
	  {
	    int lru = Integer.MAX_VALUE, val = Integer.MIN_VALUE;
	    
Iterator < Integer > itr = s.iterator ();
	    
while (itr.hasNext ())
	      
	      {
		int temp = itr.next ();
		if (index.get (temp) < lru)
		  
		  {
		    lru = index.get (temp);
		    val = temp;
		  
}
	      
}
	    
if (!s.contains (arr[i]))
	      
	      {
		
s.add (arr[i]);
		
page_faults++;
	      
}
	    else
	      {
		
page_hits++;
	      
}
	    
 
s.remove (val);
	    
s.add (arr[i]);
	    index.put (arr[i], i);
	  
}
	
 
System.out.println (" " + s);
      
}
    
System.out.println ("Page Hits = " + page_hits);
    
System.out.println ("Page Faults = " + page_faults);
  
 
}
  
 
public static void main (String arg[]) 
  {
    
lru pra = new lru ();
    pra.lru ();

} 
 
} 
 
