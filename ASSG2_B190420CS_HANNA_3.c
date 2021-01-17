#include<stdio.h>
#include<stdlib.h>

int* a;
int* b;

int binarysearch(int beg,int end,int x)
{ 
 if(beg>end)
    return (-1);
  
 int mid=(beg+end)/2;
 
 if(x==*(a+mid))
  {
  	if(x==*(a+mid-1))
  	 binarysearch(beg,mid-1,x);
  	else
  	 return mid;
  }
  
 else if(x<*(a+mid))
  binarysearch(beg,mid-1,x);
  
 else 
  binarysearch(mid+1,end,x);
	
}
void main()
{   
    int n,m,i;
    scanf("%d",&n);
    scanf("%d",&m);
	
	a=(int*)malloc(n*sizeof(int));
	b=(int*)malloc(m*sizeof(int));
	
	for(i=0;i<n;i++)
    	scanf("%d",a+i);
    	
    for(i=0;i<m;i++)
        scanf("%d",b+i);
        
    for(i=0;i<m;i++)
        printf("\n%d",binarysearch(0,n-1,*(b+i)));
        
}
