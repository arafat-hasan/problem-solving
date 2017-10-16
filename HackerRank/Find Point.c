#include <stdio.h>

int main() {

    int T,px,py,qx,qy,w,e;
    scanf("%d",&T);
    for(;T>0;T--){
        scanf("%d %d %d %d",&px,&py,&qx,&qy);
        w=(px-2*qx)/(-2);
        e=(py-2*qy)/(-2);
        printf("%d %d\n",w,e);
    }
    return 0;
}
