#include <stdio.h>
int solveMeFirst(int a, int b)
{
    return a+b;
}
int main()
{
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    printf("%d",solveMeFirst(num1,num2));
    return 0;
}
