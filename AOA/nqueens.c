#include <stdio.h>
#include <stdlib.h>

int z = 4;
int a[4];

int place(int j,int p){
    for(int x = 0;x<j;x++){
        if(a[x] == p || abs(a[x]-p) == abs(x-j)){
            return 0;
        }
    }
    return 1;
}

void Nqueen(int k,int n){
    for(int i=0;i<n;i++){
        if(place(k,i) == 1){
            a[k] = i;
            if(k == n-1){
                for(int u=0;u<n;u++){
                    printf("%d ",a[u]);
                }
                printf("\n");
            }
            else{
                Nqueen(k+1,n);
            }
        }
    }
}

int main()
{
    Nqueen(0,z);
    return 0;
}
