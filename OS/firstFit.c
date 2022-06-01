#include <stdio.h>

int main(){
    int slots[4] = {100,200,300,400};
    int process[4] = {300, 450, 125, 50};
   
    for (int i=0;i<4;i++) // for every process
    { 
     
        for (int j=0;j<4;j++) // checking slots
        {
           
           if(process[i]<=slots[j])
           {
               
               printf("%d-%d \n", process[i], slots[j]);
               slots[j] = slots[j] - process[i];
               
               
               break;
           }
          
        }
    }
    for(int i=0;i<4;i++)
    {
        printf("%d ",slots[i]);
    }

    return 0;
}