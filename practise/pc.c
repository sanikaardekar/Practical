#include<stdio.h>
int n=0,s=0,e=4,b[4];
int wait(int *s){
return(--*s);
}
int signal(int *s){
return(++*s);
}
void producer(){
int a;
wait(&e);
wait(&s);
printf("how many to produce?");
scanf("%d",&a);
b[n]=a;
signal(&s);
signal(&n);
for(int i=0;i<n;i++){
printf("%d",b[i]);
}
printf("\n");
}
void consumer(){
wait(&n);
wait(&s);
for(int i=1;i<n;i++){
b[i-1]=b[i];
}
signal(&s);
signal(&e);
for(int i=0;i<n;i++){
printf("%d",b[i]);
}
printf("\n");
}
int main(){
int c;
do{
printf("Choose\n 1.producer\n 2.consumer\n 3.exit\n");
scanf("%d",&c);
switch(c){
case 1:
if(e==0){
printf("buffer full\n");
}
else{
producer();
}
break;
case 2:
if(e==4){
printf("buffer empty\n");
}
else{
consumer();
}
break;
case 3:
break;
default:
printf("invalid choice\n");
}
}while(c!=3);
return 0;
}