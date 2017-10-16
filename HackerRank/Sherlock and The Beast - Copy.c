#include<stdio.h>
void dig(int n,int m);
int main() {
    int m,N,T;
    scanf("%d",&T);
    for(; T>0; T--) {
        scanf("%d",&N);
        m=N%3;
        if(m==2&&(N-5)>-1)
            dig(N-5,N);
        else if(m==0&&N>0)
            dig(N,0);
        else if(m==1&&(N-10)>-1)
            dig(N-10,N);
        else
            printf("-1\n");
    }
    return 0;
}
void dig(int n,int m) {
    int i;
    char dig[100000];
    for(i=0; i<n; i++)
        dig[i] = '5';
    for(; i<m; i++)
        dig[i]='3';
    dig[i]='\0';
    printf("%s\n",dig);
}
