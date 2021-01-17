#include<stdio.h>
#include<stdlib.h>

int c=0;
int noi=0;

void Print(int* a, int n)
{
	int i;
	for(i=0;i<n;i++)
	 printf("%d ",*(a+i));
}

void Merge(int* a, int p, int q, int r)
{
	int n1, n2,i,j,k;
    n1=q-p+1;
    n2=r-q;
    
    int* L;
    L=(int*)malloc(n1*sizeof(int));
    int* R;
    R=(int*)malloc(n2*sizeof(int));
    
    for(i=0;i<n1;i++)
     *(L+i)=*(a+p+i);
    for(j=0;j<n2;j++)
     *(R+j)=*(a+q+j+1);

    *(L+i)=9999;
    *(R+j)=9999;
    i=0; j=0;
    
    for(k=p;k<=r;k++)
    {   
    	if(*(L+i)<=*(R+j))
    	 {
		 *(a+k)=*(L+i);
		 i++;
	    }
	    else
	    {
	    	*(a+k)=*(R+j);
	    	j++; noi=noi+n1-i;
		}
		c++;
	}
}
    
void Merge_Sort(int* a, int p, int r)
{   int q;

	if(p<r)
	{
		 q=(p+r)/2;
		Merge_Sort(a,p,q);
		Merge_Sort(a,q+1,r);
		Merge(a,p,q,r);
	}
}

void main()
{
	int i,n;
	scanf("%d",&n);
	
	int* a;
	a=(int*)malloc(n*sizeof(int));
	
	for(i=0;i<n;i++)
	 scanf("%d",a+i);
	
	Merge_Sort(a,0,n-1);
	
	Print(a,n);
	
	printf("\n%d",c);
	printf("\n%d",noi);
			
}

