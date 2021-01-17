#include<stdio.h>
#include<stdlib.h>

int c=0;
void PARTITION(int* A,int p,int* q,int r)
{
	int x=*(A+r),i,j,temp;
	i=p-1;
	for(j=p;j<r;j++)
	 {
	  c++;	
	  if(*(A+j)<=x)
	   {
	   	 i++;
	   	 temp=*(A+i);
	  	 *(A+i)=*(A+j);
	  	 *(A+j)=temp;
	   }
     }
	temp=*(A+i+1);
	*(A+i+1)=*(A+r);
	*(A+r)=temp;
	*q= i+1;
}

void QUICK_SORT(int* A,int p,int r)
{    int q;
	if(p<r)
	{ 
	  
	  PARTITION(A,p,&q,r);
	  QUICK_SORT(A,p,q-1);
	  QUICK_SORT(A,q+1,r);	
	}
}
void PRINT(int* A,int n)
{
	int i;
	for(i=0;i<n;i++)
	 printf("%d ",*(A+i));
}

void main()
{
	int n,i;
	scanf("%d",&n);
	int* A=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	 scanf("%d",A+i);
	QUICK_SORT(A,0,n-1);
	PRINT(A,n);
	printf("\n%d",c);
}
