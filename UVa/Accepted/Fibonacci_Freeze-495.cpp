/*
 * FILE: Fibonacci_Freeze-495.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK: https://uva.onlinejudge.org/external/4/495.pdf
 *
 * Description:
 *
 *
 *	DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    31 Jan 2017    New             1.0		Completed, AC
 *
 *
 */


#include <cstdio>
#include <cstring>
#define FOR(a, b) for (int i=a; i<=b; i++)

using namespace std;

typedef long long ll;
void fibbonacci(int f);
void sumofstr(char* a, char* b, char* c);
int sum_c(int a,int b,int c);
int sum_s(int a,int b,int c);
char *strrev(char *str);
char fib[5001][10000];

int main() {

    fibbonacci(5000);
    int n;
    while(scanf("%i", &n) == 1) {
        printf("The Fibonacci number for %i is %s\n", n, &fib[n][0]);
    }
    return 0;
}


void fibbonacci(int f) {
    fib[0][0] = '0';
    fib[0][1] = '\0';
    fib[1][0] = '1';
    fib[2][0] = '1';
    fib[1][1] = '\0';
    fib[2][1] = '\0';
    FOR(3, f) {
        sumofstr(&fib[i-1][0] , &fib[i-2][0], &fib[i][0]);
    }
}


void sumofstr(char* a, char* b, char* c) {

    int len_a, len_b, i, j, k, carry;
    len_a = strlen(a);
    len_b = strlen(b);

    carry = 0;
    for(k = 0, i = len_a-1, j = len_b-1; i >= 0 && j >= 0; j--, i--, k++) {
        c[k] = sum_s(a[i]-48, b[j]-48, carry)+48;
        carry = sum_c(a[i]-48, b[j]-48, carry);
    }

    if(i>=0 && i != j)
        for(; i >= 0; i--, k++) {
            c[k] = sum_s(a[i]-48, 0, carry)+48;
            carry = sum_c(a[i]-48, 0, carry);
        }


    else if(j>=0 && i != j)
        for(; j >= 0; j--, k++) {
            c[k] = sum_s(0, b[j]-48, carry)+48;
            carry = sum_c(0, b[j]-48, carry);
        }


    if(carry != 0)
        c[k++] = carry + 48;
    c[k] = '\0';
    strrev(c);

}


int sum_s(int a,int b,int c) {
    if(a+b+c>9)
        return (a+b+c)%10;
    return a+b+c;
}

int sum_c(int a,int b,int c) {
    if(a+b+c>9)
        return (a+b+c)/10;
    return 0;
}


char *strrev(char *str) {
    char *p1, *p2;
    if (! str || ! *str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}
