#include <stdio.h>
#include <stdlib.h>

int z = 4;
int a[4];

int place(int k,int i){
    for(int j = 0;j<k;j++){
        if(a[j] == i || abs(a[j]-i) == abs(j-k)){
            return 0;//flse
        }
    }
    return 1;//true
}

void Nqueen(int k,int n){
    for(int i=0;i<n;i++){
        if(place(k,i) == 1){
            a[k] = i;//imppp
            if(k == n-1){//impp
                for(int u=0;u<n;u++){//printing
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
