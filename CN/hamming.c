#include <stdio.h>
void generate()
{
    int n=7;
    int a[7],i;
    int count1=0;
    int count2=0;
    int count4=0;
    printf("Enter the data bits:");
    for(i=1;i<=n;i++)
    {
        if(i==1 || i==2 || i==4)
        {
            //continue;
            a[i]=-1;
        }
        else
        {
            scanf("%d",&a[i]);
        }
    }
    for(i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    for(i=1;i<=n;i++)
    {
        if(i==3 || i==5 ||i==7)
        {
            if(a[i]==1)
            {
                count1++;
            }
        }
        if(i==3 || i==6 ||i==7)
        {
            if(a[i]==1)
            {
                count2++;
            }
        }
        if(i==5 || i==6 ||i==7)
        {
            if(a[i]==1)
            {
                count4++;
            }
        }
         
    }
    if(count1%2==0)
    {
        a[1]=0;
    }
    else
    {
        a[1]=1;
    }
    if(count2%2==0)
    {
        a[2]=0;
    }
    else
    {
        a[2]=1;
    }
    if(count4%2==0)
    {
        a[4]=0;
    }
    else
    {
        a[4]=1;
    }
    printf("The generated hamming code is:\n");
     for(i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
   
}
void detect_correct()
{
        int n1=7;
    int i,h[7];
    printf("Enter the hamming code:");
    for(i=1;i<=7;i++)
    {
        scanf("%d",&h[i]);
    }
    printf("Hamming code is:\n");
    for(i=1;i<=7;i++)
    {
        printf("%d ",h[i]);
    }
    printf("\n");
    int arr[3];
    int p1=h[1]+h[3]+h[5]+h[7];
    int p2=h[2]+h[3]+h[6]+h[7];
    int p4=h[4]+h[5]+h[6]+h[7];
        if(p1%2==0)
        {
            printf("No error in p1\n");
            arr[3]=0;
        }
        else
        {
           printf("error in p1\n");
            arr[3]=1; 
        }
        if(p2%2==0)
        {
            printf("No error in p2\n");
            arr[2]=0;
        }
        else
        {
           printf("error in p2\n");
            arr[2]=1; 
        }
        if(p4%2==0)
        {
            printf("No error in p4\n");
            arr[1]=0;
        }
        else
        {
           printf("error in p4\n");
            arr[1]=1; 
        }
    for(i=1;i<=3;i++)
    {
        printf("\n%d",arr[i]);
    }
    int k=0;
    for (i=1;i<=3;i++)
        k = 10 * k + arr[i];
    printf("\nThe binary equivalent is %d\n",k);
    int binary_num, decimal_num = 0, base = 1, rem;  
  
    binary_num = k; 
      
      
    while ( k > 0)  
    {  
        rem = k % 10;  
        decimal_num = decimal_num + rem * base;  
        k = k / 10;
        base = base * 2;  
    }  
    printf ("The decimal number is %d\n", decimal_num);
    if(h[decimal_num]==1)
    {
        h[decimal_num]=0;
    }
    else
    {
        h[decimal_num]=1;
    }
    printf("The corect hamming code is:\n");
    for(i=1;i<=n1;i++)
    {
        printf("%d ",h[i]);
    }
}
int main()
{
    int c;
    
    do{
        printf("\nMENU\n1.GENERATE HAMMING CODE\n2.DETECT AND CORRECT HAMMING CODE\n3.EXIT\n");
        printf("Enter your choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                generate();
                break;
            case 2:
                detect_correct();
                break;
            default:
                printf("EXIT");
                break;
        }
    }while(c!=3);
    

    return 0;
}