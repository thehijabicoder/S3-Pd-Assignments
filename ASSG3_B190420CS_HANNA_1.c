#include<stdio.h>
#include<stdlib.h>

int c=0;

void Print(int* x, int k)
{ int i;
	for(i=0;i<k;i++)
	 printf("%d ",*(x+i));
}

void Insertion_Sort(int* a,int n)
{
  	int i,j,key, count=0;
  	
  	for(j=1;j<n;j++)
  	{  
	   key=*(a+j);
	   i=j-1;
	   
	   while(i>=0 && *(a+i)>key)
	   {  c++;
		 *(a+i+1)=(*(a+i));
		  i--;  
	   }
	   
	   if(i>=0)
	      c++;
	      
	   *(a+i+1)=key;
	    
	}

}

void main()
{
	int n,i, x;
	scanf("%d",&n);
	
	int* a;
	a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    	scanf("%d",a+i);
    	
    Insertion_Sort(a,n);
    
    Print(a,n);
    
    printf("\n%d",c);
}

