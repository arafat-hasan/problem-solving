#include <stdio.h>
#include <math.h>
int main()
{
    int T,a,b;
    scanf("%d",&T);
    while(scanf("%d%d",&a,&b)==2)
    {
        printf("%d\n",(int)(floor(sqrt(b))-ceil(sqrt(a))+1));
    }
    return 0;
}
