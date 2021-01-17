#include<stdio.h>

 long long int fact(int x)
 {
 	if(x==0)
 	 return 1;
 	else
 	 return x*fact(x-1);
 }
 void main()
 {
 	int n;
 	scanf("%d",&n);
 	printf("%lld",fact(n));
 }
