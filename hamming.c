#include <stdio.h>
int main(){
    // int c1[3] = {3,5,7};
    // int c2[3] = {3,6,7};
    // int c4[3] = {5,6,7};
    int bits[4];
    int code[7];
    
    for(int i=0;i<4;i++)
    {
        printf("enter the bits:\n");
        scanf("%d",&bits[i]);
    } 
    int j=0;
    for(int i=6;i>=0;i--)
    {
        if(i==0 || i==1 || i==3)
        {
            code [i] = -1;
            
            
        }
        else{
        code[i]=bits[j];
        j++;
        }
    }
    printf("raw code\n");
    for(int i=6;i>=0;i--)
    {
      printf("%d ", code[i]);
    }
    printf("\n");
   
    if((code[2]+code[4]+code[6]) %2 == 0)//p1
    {
        code[0] = 0;
    }
    else{
        code[0] = 1;
    }
    
    
    if((code[2]+code[5]+code[6]) %2 == 0)//p2
    {
        code[1] = 0;
    }
    else{
        code[1] = 1;
    }
    
    if((code[5]+code[4]+code[6]) %2 == 0)//p4
    {
        code[3] = 0;
    }
    else{
        code[3] = 1;
    }
    printf("final code\n");
    for(int i=6;i>=0;i--)
    {
      printf("%d ", code[i]);
    }
    return 0; 
}