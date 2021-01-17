#include<stdio.h>
#include<stdlib.h>

void linearsearch(int* b, int q, int y)
{int i=0,count=0;

 while(i<q)
 { 
 
 if(y==*(b+i))
  printf("%d ",i);
 else 
  count++;
  
 i++;
 }
 
 if(count==q)
  printf("%d ",-1);

}

void main()
{
	int n,x,i;
	scanf("%d",&n);
	
	int* a;
     a=(int*)malloc(n*sizeof(int));
	
	for(i=0;i<n;i++)
	 scanf("%d ",a+i);
	 
	scanf("%d",&x);
	linearsearch(a,n,x);
	
	
}
