#include<stdio.h>
int x[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int h[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int y[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int l1,l2,N;
int i,n,k;
void main()
{
printf("Enter length of x: ");
scanf("%d",&l1);
printf("Enter x[20]:\n ");
for(i=0;i<l1;i++)
    scanf("%d",&x[i]);
printf("Enter the length of h: ");
scanf("%d", &l2);
printf("Enter h[20]:\n");
for(i=0;i<l2;i++)
    scanf("%d",&h[i]);
N=l1+l2-1;
for(n=0;n<N;n++)
{
        y[n]=0;

        for(n=0;n<N;n++){
            if(n-k>=0 && n-k<l2)
                y[n]=y[n]+x[k]*h[n-k];
}
}
printf("Convolution result y[n] = \n");
for(n=0;n<N;n++)
    printf("%d\n",y[n]);
}
