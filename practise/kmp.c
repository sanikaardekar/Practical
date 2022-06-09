#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void kmp(const char* text, const char* pat, int n, int m){
if(*pat=='\0' || m==0){
printf("pattern occurs w a shift of 0\n");
}
else if(*text=='\0' || m>n){
printf("pattern doesnt exist\n");
} 
int next[m+1];//pat
for(int i=0;i<m+1;i++){
next[i]=0;
}
for(int i=1;i<m;i++){
int j=next[i+1];
while(j>0 && pat[i]!=pat[j]){
j=next[j];
}
if(j>0 && pat[i]==pat[j]){
next[i+1]=j+1;
}
}
int i,j;
for(i=0,j=0;i<n;i++){ //text
if(*(text+i)==*(pat+j)){
if(++j==m){ //pat
printf("pattern occurs at %d\n",i-j+2);
}
}
else if(j>0){
i--;
j=next[j];
}
}
}


int main(){
char* text = "abcdabaccbbdabcab";
char* pat = "dab";
int n=strlen(text);
int m=strlen(pat);
kmp(text,pat,n,m);
return 0;
}