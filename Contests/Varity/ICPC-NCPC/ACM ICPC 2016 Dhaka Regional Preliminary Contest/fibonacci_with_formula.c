#include<stdio.h>
#include<math.h>
int main()
{
    double n1,n,f;
    scanf("%lf",&n1);
    n=n1+1;
     f=((pow(((1+sqrt(5))/2),n))-(pow(((1-sqrt(5))/2),n)))/sqrt(5);
    printf("%.0lf\n",f);
    return 0;
}
