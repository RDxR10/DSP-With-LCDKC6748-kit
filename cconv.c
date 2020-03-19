#include<stdio.h>
int x[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int h[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int y[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int m,N,sum;
int i,n,k;

void main()
{
printf("Enter N:");
scanf("%d",&N);
printf("Enter x[20]:\n");
for(i=0;i<N;i++)
    scanf("%d",&x[i]);
printf("Enter h[20]:\n");
for(i=0;i<N;i++)
    scanf("%d",&h[i]);

printf("\n The circular convolution is:...");
for(m=0;m<N;m++)
{
sum=0.0;
for(k=0;k<N;k++){
    if((m-k)>=0)
        n=m-k;
    else
        n=m-k+N;
        sum+=x[k]*h[n];

//y[m]=sum;
//printf("\ny[%d]=%d",m,y[m]);
}
y[m]=sum;
printf("\ny[%d]=%d",m,y[m]);
}
//printf("\ny[%d]=%d",m,y[m]);
}
