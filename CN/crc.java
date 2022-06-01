import java.util.*;
class crc
{
  public static void main (String[]args)
  {
    int n, i;
    Scanner s = new Scanner (System.in);
      System.out.print ("Enter the number of bits in the data : ");
      n = s.nextInt ();
    int data[] = new int[n];
    for (i = 0; i < n; i++)
      {
	System.out.print ("Enter the databit : ");
	data[i] = s.nextInt ();
      }
    System.out.print ("Enter the number of bits in the divisor data : ");
    n = s.nextInt ();
    int divisor[] = new int[n];
    for (i = 0; i < n; i++)
      {
	System.out.print ("Enter the databit in the divisor data : ");
	divisor[i] = s.nextInt ();
      }
    int remainder[] = divide (data, divisor);
    for (i = 0; i < remainder.length - 1; i++)
      {
	System.out.print (remainder[i]);
      }
    System.out.println ();
    System.out.println ("The CRC code is : ");
    for (i = 0; i < data.length; i++)
      {
	System.out.print (data[i]);
      }
    for (i = 0; i < remainder.length - 1; i++)
      {
	System.out.print (remainder[i]);
      }
    System.out.println ();
    int sent_data[] = new int[data.length + remainder.length - 1];
    System.out.println ("Enter the data to be sent : ");
    for (i = 0; i < sent_data.length; i++)
      {
	System.out.print ("Enter the data bit in the sent data : ");
	sent_data[i] = s.nextInt ();
      }
    recieve (sent_data, divisor);
  }
  static int[] divide (int original_data[], int divisor[])
  {
    int remainder[], i, j;
    int data[] = new int[original_data.length + divisor.length];
    System.arraycopy (original_data, 0, data, 0, original_data.length);
    remainder = new int[divisor.length];
    System.arraycopy (data, 0, remainder, 0, divisor.length);
    for (i = 0; i < original_data.length; i++)
      {
	System.out.println ("First data bit is : " + remainder[0]);
	System.out.print ("Remainder : ");
	if (remainder[0] == 1)
	  {
	    for (j = 1; j < divisor.length; j++)
	      {
		remainder[j - 1] = exor (remainder[j], divisor[j]);
		System.out.print (remainder[j - 1]);
	      }
	  }
	else
	  {
	    for (j = 1; j < divisor.length; j++)
	      {
		remainder[j - 1] = exor (remainder[j], 0);
		System.out.print (remainder[j - 1]);
	      }
	  }
	remainder[divisor.length - 1] = data[i + divisor.length];
	System.out.println (remainder[divisor.length - 1]);
      }
    return remainder;
  }
  static int exor (int a, int b)
  {
    if (a == b)
      {
	return 0;
      }
    return 1;
  }
  static void recieve (int data[], int divisor[])
  {
    int i;
    int remainder[] = divide (data, divisor);
    for (i = 0; i < remainder.length; i++)
      {
	if (remainder[i] != 0)
	  {
	    System.out.print ("There is an error in the recieved data.");
	    return;
	  }
      }
    System.out.println ("Data was recieved without any error.");
  }
}
