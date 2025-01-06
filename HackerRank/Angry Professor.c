#include <stdio.h>
int main()
{
    int t,j,i,p,n;
    scanf("%d",&t);
    for(j = 0; j < t; j++)
    {
        int n;
        int k;
        scanf("%d %d",&n,&k);
        int a[n];
        p=0;
        for(i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<=0)
                p++;
        }
        if(p>=k)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
