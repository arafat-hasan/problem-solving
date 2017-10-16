//Shopaholic_Solution-11369.cpp
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
  int n,t,price[20001],i,j;
  long int discount;

  scanf("%d",&t);

  for(i=0;i<t;i++)
  {  discount=0;
      scanf("%d",&n);
      for(j=0;j<n;j++)
      scanf("%d",&price[j]);

      sort(price,price+n);
      for(j=n-3;j>=0;j=j-3)
         discount=discount+price[j];
         
      printf("%ld\n",discount);
      
      }
      return 0;
      }
