#include <stdio.h>


int graph[][7] = {
        {0,6,5,5,0,0,0},
        {0,0,0,0,-1,0,0},
        {0,-2,0,0,1,0,0},
        {0,0,-2,0,0,-1,0},
        {0,0,0,0,0,0,3},
        {0,0,0,0,0,0,3},
        {0,0,0,0,0,0,0}
    };

int d[7];
int par[7];
int infi = 100000;
int v=7;

int main()
{


    for(int i=0;i<7;i++){
        d[i] = infi;
        par[i] = -1;
    }
    d[0] = 0;

    for(int i=0;i<v-1;i++){//i-->v-1
        for(int j=0;j<v;j++){
            for(int k=0;k<v;k++){
                if(graph[j][k]!=0){
                     if(d[j]+graph[j][k] < d[k]){
                        d[k] = d[j] +graph[j][k];
                        par[k] = j;
                        }   
                }
            }
        }
    }
//negative cycle check
    for(int i=0;i<v;i++){
        for(int j=0;j<7;j++){
            if(d[i] + graph[i][j] < d[j]){
                for(int k=0;k<7;k++){
                printf("node = %d parent = %d dist = %d \n",k+1,par[k],d[k]);
                }
                printf("Graph contains negative cycle");
                return 0;
            }
        }
    }

    for(int i=0;i<7;i++){
        printf("node = %d parent = %d dist = %d \n",i+1,par[i],d[i]);
    }


    return 0;
}
