#include<stdio.h>
unsigned long long int dig(int n);
int main() {
    int m,N,T;
    scanf("%d",&T);
    for(; T>0; T--) {
        scanf("%d",&N);
        m=N%3;
        if(m==2&&(N-5)>-1) {
            printf("%lld\n",dig(N-5)*100000+33333);
        } else if(m==0) {
            printf("%lld\n",dig(N));
        } else if(m==1&&(N-10)>-1) {
            printf("%lld\n",dig(N-10)*1000000000+3333333333);
        } else
            printf("-1\n");
    }
    return 0;
}
unsigned long long int dig(int n) {
    int i,dig=0;
    for(i=0; i<n; i++) {
        dig = dig *10;
        dig = dig + 5;
    }
    return dig;
}
