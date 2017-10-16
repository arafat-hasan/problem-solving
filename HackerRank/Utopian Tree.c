#include<stdio.h>
int main() {
    int t,i,j,y,n;
    scanf("%d",&t);
    for(j=0; j<t; j++) {
        scanf("%d",&y);
        n=1;
        for(i=1; i<=y; i++) {
            if(i%2==0)
                n=n+1;
            else
                n=n*2;
        }
        printf("%d\n",n);
    }
    return 0;
}
