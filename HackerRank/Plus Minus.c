#include <stdio.h>
int main()
{
    int n,i,p=0,N=0,z=0;
    scanf("%d",&n);
    int arr[n];
    for(i = 0; i< n; i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]>0)
            ++p;
        else if(arr[i]<0)
            ++N;
        else
            ++z;
    }
    printf("%lf\n%lf\n%lf\n",(double)p/(double)n,(double)N/(double)n,(double)z/(double)n);
    return 0;
}
