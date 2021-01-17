#include<stdio.h>
#include<math.h>
#include<stdlib.h>

 int gcd(int x,int y)
 { 
   if(y==0&&x==0)
    return (-1);
   else if(y==0)
    return abs(x);
   else
    gcd(y,x%y);
 	 
 }
 void main()
 {
 	int a,b;
 	scanf("%d %d",&a,&b);
 	
 	printf("%d",gcd(a,b));
 }

