#include<stdio.h>
#include<stdlib.h>

void swap(int* p, int x)
{
	int temp;
	temp=*(p+x);
	*(p+x)=*(p+x+1);
	*(p+x+1)=temp;
}

void main()
{
	int n,i,j;
	scanf("%d",&n);
	
    int* a;
	a=(int*)malloc(n*sizeof(int));
	
	for(i=0;i<n;i++)
	 scanf("%d ",a+i);
	 
	for(i=0;i<n;i++)
	 for(j=0;j<n-1-i;j++)
      if(*(a+j)>*(a+j+1))
	   swap(a,j);
	   
	for(i=0;i<n;i++)
	 printf("%d ",*(a+i));	 
	
		
}
