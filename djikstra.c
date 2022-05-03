#include <stdio.h>
#define V 9
#define MAX 100
int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                    { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                    { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                    { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                    { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                    { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                    { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                    { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                    { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    
int min(int d[],int spt[]){
    int dmin=MAX,min_index;
    for(int i=0;i<V;i++){
        if(d[i]<=dmin && spt[i]!=1){
            dmin=d[i];
            min_index=i;
        }
    }
    // printf("%d",min_index);
    return min_index;
}

int main()
{   
    int d[V];
    int prnt[V];
    int spt[V];
    for(int i=0;i<V;i++){
        d[i]=MAX;
        spt[i]=0;
        prnt[i]=-1;
    }
    d[0]=0;
        for(int i=0;i<V;i++){
            int j=min(d,spt);
            spt[j]=1;
            for(int k=0;k<V;k++){
                if(graph[j][k]!=0 && spt[k]!=1 &&d[k]>graph[j][k]+d[j] ){
                    // printf("%d %d\n",j,k);
                    d[k]=graph[j][k]+d[j];
                    prnt[k]=j;
                }
            }
        }
    for(int i=0;i<V;i++){
        printf("node %d distance %d parent %d\n",i,d[i],prnt[i]);
    }
 
    return 0;
}