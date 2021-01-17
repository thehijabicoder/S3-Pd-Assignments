#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct heap
{
	int heapsize;
	int* b;
}heap;

void swap(heap* q,int i,int j)
{
	int temp;
	temp=*(q->b+i);
	*(q->b+i)=*(q->b+j);
	*(q->b+j)=temp;
}
void min_heapify(heap* q,int i)
{
	int smallest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<q->heapsize && *(q->b+l)<*(q->b+smallest))
	 smallest=l;
	if(r<q->heapsize && *(q->b+r)<*(q->b+smallest))
	 smallest=r;
	if(smallest!=i)
	 {
	 	swap(q,i,smallest);
	 	min_heapify(q,smallest); 
     }
}

void change_token_number(heap* q,int k,int x)
{   int i;
    for(i=0;i<q->heapsize;i++)
    {
    	if(*(q->b+i)==k)
    	{
			*(q->b+i)=x;
    	    while(i>0 && *(q->b+(i-1)/2)>*(q->b+i))
	       {
		     swap(q,(i-1)/2,i);
		     
		     i=(i-1)/2;
	       }
	       
	       break;
	   }
         
	}

}

void get_next_patient(heap* q)
{
	if(q->heapsize<=0)
	  printf("%d\n",-1);
	else
	 printf("%d\n",*(q->b));
}

void extract_next_patient(heap* q)
{
	if(q->heapsize<=0)
	   printf("%d\n",-1);
   else
   {
    int min=*(q->b);
    *(q->b)=*(q->b+(q->heapsize)-1);
    q->heapsize=q->heapsize-1;
    min_heapify(q,0);
    printf("%d\n",min);
   }
}



void insert_patient(heap* q, int k)
{
	q->heapsize=q->heapsize+1;
	*(q->b+(q->heapsize)-1)=9999999;
    change_token_number(q,9999999,k);
}

void display_queue(heap* q)
{
	int i,j,k;
	printf("\n%d",*(q->b));
	
	k=0;
	for(i=1;i<q->heapsize;i=i+pow(2,k))
	 {k++;
	  for(j=i+1;j<i+pow(2,k);j++)
	  {
	  	if(*(q->b+i)<*(q->b+j))
	  		printf(" %d",*(q->b+i));
	  }}

}
void main()
{
	 heap q;
	 q.heapsize=0;
     q.b=(int*)malloc(999999*sizeof(int));
     
     int i,k;
	 
     
	char ch;
	menu:
	scanf("%c",&ch);
	switch(ch)
	{
      case 'i': scanf("%d",&k);
                insert_patient(&q,k);
	            break;
      case 'e': extract_next_patient(&q);
	            break;
      case 'm': get_next_patient(&q);
	            break;
	  case 'c': scanf("%d %d",&i,&k);
	            change_token_number(&q,i,k);
	  	        break;
      case 'd': display_queue(&q);
	            break;
      case 's':exit(0); break;
	  	
	}
   goto menu;
}
