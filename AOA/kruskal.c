#include <stdio.h>
#define n 9
int parent[n],rank[n];
int minans[2]={-1,-1}; //storing temporary minimum edge vertices
int G[][n]={        //adjacency matrix for given undirected graph
    {0,4,0,0,0,0,0,0,8},
    {4,0,8,0,0,0,0,0,11},
    {0,8,0,7,0,4,0,2,0},
    {0,0,7,0,9,14,0,0,0},
    {0,0,0,9,0,10,0,0,0},
    {0,0,10,14,4,0,2,0,0},
    {0,0,0,0,0,2,0,6,1},
    {0,0,2,0,0,0,6,0,7},
    {8,11,0,0,0,0,1,7,0}
};
int find(int x){        //finding the parent of set to which x belongs
    if(parent[x]!=x){
        parent[x]=find(parent[x]);
    }
    return parent[x];
}
void unioN(int x,int y){
    int xRoot=find(x);
    int yRoot=find(y);
    if (xRoot==yRoot){
        return;
    }
    if (rank[xRoot]<rank[yRoot]){
        parent[xRoot]=yRoot;
    }
    else if (rank[yRoot]<rank[xRoot])
    {
        parent[yRoot]=xRoot;
    }
    else{
        parent[xRoot]=yRoot;
        rank[yRoot]+=1;
    }
    
}
int min(){        //finding edge with minimum cost
    int minm=100;
    for(int i=0;i<n;i++){//0 to n
        for(int j=i;j<n;j++){//i to n
            if(G[i][j]!=0 && G[i][j]<minm){
                minm=G[i][j];
                minans[0]=i;
                minans[1]=j;
            }
        }
    }
    // printf("%d %d %d\n",minans[0],minans[1],minm);
    return minm;
}
void kruskal(){
    int soli[n-1],solj[n-1];//edges in solution set
    int cost=0;             //MST cost
    int count=0; 
    while(min()<100){      
        int i=find(minans[0]);
        int j=find(minans[1]);
        if(i!=j){
            // printf("%d %d\n",i,j);
            cost=cost+G[minans[0]][minans[1]];
            unioN(minans[0],minans[1]);
            soli[count]=minans[0],solj[count]=minans[1];
            count+=1;
        }
        G[minans[0]][minans[1]]=0;
        G[minans[1]][minans[0]]=0;
    }
    for(int i=0;i<count;i++){//0 to count
        printf("(%d,%d)\t",soli[i],solj[i]);
    }
    printf("Total cost %d",cost);
}
int main()
{   
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
    kruskal();
    return 0;
}
