#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i=0;
typedef struct employees
{
  char name[1000];
  int salary;
  int workperday;
  int CL;
  int LoP;
}emp;

int COMPUTEDEDUCTIONS(emp* a,char name[])
{ int j;
	for(j=0;j<=i;j++)
	 if(strcmpi((a+j)->name,name)==0)
    	return (a+j)->LoP*1000;
}

void insert(emp* a)
{
  scanf("%[^\n]%*c %d %d %d",(a+i)->name,&(a+i)->salary,&(a+i)->workperday,&(a+i)->CL);
  
  if((a+i)->workperday==8)
     (a+i)->salary+=50;
  else if((a+i)->workperday==10)
     (a+i)->salary+=100;
  else if((a+i)->workperday>10)
     (a+i)->salary+=150;
     
  if ((a+i)->CL>5)
	    (a+i)->LoP=(a+i)->CL-5;
  else
	(a+i)->LoP=0;
  (a+i)->salary=(a+i)->salary-(a+i)->LoP*1000;
     
  i++;	
}
void print_noincrement(emp* a)
{  
    int j;
	for(j=0;j<=i;j++)
	 if((a+j)->workperday!=8&&(a+j)->workperday<10)
	  printf("%s %d %d\n",(a+j)->name,(a+j)->salary,(a+j)->workperday);
	  
}    
void print_finalsalary(emp* a)
{
  int j;
	for(j=0;j<=i;j++)
	 printf("%s %d\n",(a+j)->name,(a+j)->salary);
	 
}
void print_workperday(emp* a)
{ 
   int x,j;
    scanf("%d",&x);
	for(j=0;j<=i;j++)
	 if((a+j)->workperday==x)
	 printf("%s %d",(a+j)->name,(a+j)->salary);
	 
}
void main()
{ emp* a;
  a=(emp*)malloc(10*sizeof(emp));
 char ch;
 char name[1000];
 scan:
 scanf("%c",&ch);
  switch(ch)
    {
     case 'r': insert(a);
	           break;
     case 'i': print_noincrement(a);
	           break;
	 case 'f': print_finalsalary(a);
	           break;
	 case 'w': print_workperday(a);
	           break;
	 case 'd': scanf("%[^\n]%*c",name);
	           printf("\n%d",COMPUTEDEDUCTIONS(a,name));
	           break;
	 case 't': exit(0);
	           break;
	       
    }
 goto scan;

}
