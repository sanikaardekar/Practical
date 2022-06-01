#include <stdio.h>
struct items{
    int id;
    int arTime;
    int bstTime;
    int compTime;
    int tat;
    int wait;
    int remain;
    int priority;
    int check;
};
int main(){
    int n,counter=0;
    printf("Enter Number of Processes: ");
    scanf("%d",&n);
    struct items process[n],checkprocess[n],temp;
    printf("Enter Arrival time, Burst Time and Priority:\n");
    for(int i=0;i<n;i++){
        printf("For Process %d :",i+1);
        scanf("%d",&process[i].arTime);
        scanf("%d",&process[i].bstTime);
        scanf("%d",&process[i].priority);
        process[i].id=i+1;
        process[i].remain=process[i].bstTime;
        counter+=process[i].bstTime;
        process[i].check=0;
    }
    for(int i=0; i<n;i++){
        for(int j=0;j<n-1;j++){
            if(process[j].arTime>process[j+1].arTime){
            temp=process[j];
            process[j]=process[j+1];
            process[j+1]=temp;
            }
        }
    }
    int runningTime=0;
    if(runningTime<process[0].arTime){
        runningTime=process[0].arTime;
    }
    
    
    
    int i =0;
    printf("P2 ");
    for (int j = runningTime; j <=counter ; j++) { for (int k = 0; k < n; k++) {
    
    
    
    if(process[k].arTime<=runningTime && process[k].check==0){
        if(process[i].priority>process[k].priority){
            printf("P%d ",process[k].id);
            i=k;
        }
    }
    }
    runningTime+=1;
    process[i].remain-=1;
    if(process[i].remain==0){
        process[i].check=1;
        process[i].compTime=runningTime;
        process[i].tat=process[i].compTime-process[i].arTime;
        process[i].wait=process[i].tat-process[i].bstTime;
        process[i].priority=999;
        }
    }
    float avgWait=0.0,avgTat=0.0;
    for (int i = 0; i < n; i++) {
        avgTat+=process[i].tat;
        avgWait+=process[i].wait;
    }
    avgTat/=n;
    avgWait/=n;
    
    
   
    printf("\nResults:\n");
    printf("Pid\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",process[i].id,process[i].arTime,process[i].bstTime,process[i].compTime,process[i].tat,process[i].wait);
    }
    printf("Average TAT: %f",avgTat);
    printf("Average WT: %f",avgWait);
    return 0;
}