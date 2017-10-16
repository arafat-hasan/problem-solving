#include <stdio.h>
int main()
{
    long long n,i,a=0;
    scanf("%lld",&n);
    long long arr[n];
    for(i = 0; i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        a=arr[i]+a;
    }
    printf("%lld",a);
    return 0;
}
