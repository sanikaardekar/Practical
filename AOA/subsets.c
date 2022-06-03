#include<stdio.h>
int counter=1;//new
int n=4;
int w[4]={2,3,4,5};
int x[4]={0,0,0,0};
int m=7;
int total=0;

void sumOfSubset(int s, int k, int r){
	int j;//new
	x[k]=1;
	if(s+w[k]==m){
		printf("Solution %d: ",counter);//new
		counter++;//new
		for(j=0;j<n;j++){//condition till number of digits
			printf(" %d ",x[j]);				
		}
		printf("\n");//new
		for(j=0;j<n;j++){
			x[j]=0;//new
		}						
	}
	else if(k!=n-1 && s+w[k]+w[k+1]<=m){//new
		sumOfSubset(s+w[k],k+1,r-w[k] );	
	}
	if(s+r-w[k]>=m && s+w[k+1]<=m && k!=n-1 ){//new
		x[k]=0;
		sumOfSubset(s,k+1,r-w[k]);	
	}
	
}

int main(){
	int i;
	for(i=0;i<n;i++){
		total+=w[i];
	}
	sumOfSubset(0,0,total);
	return 0;
}