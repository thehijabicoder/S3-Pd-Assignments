#include<stdio.h>
#include<stdlib.h>


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


void min_heapify(heap* a,int i)
{
	int smallest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<a->heapsize && *(a->b+l)<*(a->b+smallest))
	 smallest=l;
	if(r<a->heapsize && *(a->b+r)<*(a->b+smallest))
	 smallest=r;
	if(smallest!=i)
	 {
	 	swap(a,i,smallest);
	 	min_heapify(a,smallest); 
     }
}

void heap_decrease_key(heap* a, int i, int k)
{
	*(a->b+i)=k;
	while(i>0 && *(a->b+(i-1)/2)>*(a->b+i))
	{
		swap(a,(i-1)/2,i);
		
		i=(i-1)/2;
	}
}

void heap_minimum(heap* a)
{
	if(a->heapsize<=0)
	  printf("%d\n",-1);
	else
	 printf("%d\n",*(a->b));
	 
}

void heap_extract_min(heap* a)
{
   if(a->heapsize<=0)
	   printf("%d\n",-1);
   else
   {
    int min=*(a->b+0);
    *(a->b)=*(a->b+(a->heapsize-1));
    a->heapsize=a->heapsize-1;
    min_heapify(a,0);
    printf("%d\n",min);
   }
   
}

	 
void min_heap_insert(heap* a, int k)
{
	a->heapsize=a->heapsize+1;
	*(a->b+(a->heapsize-1))=9999999;
	heap_decrease_key(a,a->heapsize-1,k);
}

void main()
{   
     heap a;
     a.heapsize=0;
     a.b=(int*)malloc(999999*sizeof(int));
    
     
     int i,k;
	 
     
	char ch;
	menu:
	scanf("%c",&ch);
	switch(ch)
	{
      case 'i': scanf("%d",&k);
                min_heap_insert(&a,k);
	            break;
      case 'e': heap_extract_min(&a);
	            break;
      case 'm': heap_minimum(&a);
	            break;
      case 'd': scanf("%d %d",&i,&k);
	            heap_decrease_key(&a,i,k);
	            break;
      case 's':exit(0); break;
	  	
	}
   goto menu;
}
