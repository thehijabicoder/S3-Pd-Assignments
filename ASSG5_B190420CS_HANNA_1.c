#include<stdio.h>
#include<stdlib.h>


int c=0;

typedef struct heap
{
	int heapsize;
	int* b;
}heap;


void swap(heap* a,int i,int j)
{
	int temp;
	temp=*(a->b+i);
	*(a->b+i)=*(a->b+j);
	*(a->b+j)=temp;
}

void Max_Heapify(heap* a, int i)
{
    int largest=i;
	int l= 2*i+1;
	int r= 2*i+2;
	
	if(l<a->heapsize)
	{ 
	  c++;
	  if(*(a->b+l)>*(a->b+largest))
	     largest=l;
	  
    }
     
	if(r<a->heapsize)
	{
     c++;	
	 if (*(a->b+r)>*(a->b+largest))
	    largest=r; 
    }
    
	if(largest!=i)
	{ 
	  swap(a,i,largest);
	  Max_Heapify(a,largest);
    }
  
}

void build_max_heap(heap* a)
{    int i;

	for(i=a->heapsize/2-1;i>=0;i--)
    	Max_Heapify(a,i);
}

void Heapsort(heap* a)
{   
    build_max_heap(a);
    int i;
    int n=a->heapsize;
    for(i=n-1;i>=0;i--)
    { 
    	swap(a,0,i);
    	a->heapsize--;
    	Max_Heapify(a,0);
    	
	}
	
}

void main()
{  
    heap a;
     
	int i,n;
	scanf("%d",&(a.heapsize));
	a.b=(int*)malloc(a.heapsize*sizeof(int));
	n=a.heapsize;
	
	

	for(i=0;i<a.heapsize;i++)
	 scanf("%d",a.b+i);
	 
	Heapsort(&a);
	 
	for(i=0;i<n;i++)
	 printf("%d ",*(a.b+i));
	
	printf("\n%d",c);
	 
	 
}
