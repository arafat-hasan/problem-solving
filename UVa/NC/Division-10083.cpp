/*
 * FILE: Division-10083.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK:
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    ** *** 2017    New             0.0
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

#define FileIn(file) freopen("input.txt", "r", stdin)
#define FileOut(file) freopen("output.txt", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define uint64 unsigned long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define nl cout << endl

#define INF 500000000
#define maxN 32001
#define PI acos(-1.0)
#define maxS 100000000


typedef long long ll;
using namespace std;






char *strrev(char *str) { 
    char *p1, *p2;
    if (! str || ! *str) return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

/**************************Big Number*******************************/
int sum_s(int a,int b,int c) { //Used by BIG_INT_SUM & BIG_INT_MUL
    if(a+b+c>9) return (a+b+c)%10;
    return a+b+c;
}
int sum_c(int a,int b,int c) { //Used by BIG_INT_SUM & BIG_INT_MUL
    if(a+b+c>9) return (a+b+c)/10;
    return 0;
}
int mul_s(int a,int b,int c) { //Used by BIG_INT_MUL
    if(a*b+c>9) return (a*b+c)%10;
    return a*b+c;
}
int mul_c(int a,int b,int c) { //Used by BIG_INT_MUL
    if(a*b+c>9) return (a*b+c)/10;
    return 0;
}

void BIG_INT_SUM(char* a, char* b, char* c) {	// a + b = c

    int len_a, len_b, i, j, k, carry;
    len_a = strlen(a);
    len_b = strlen(b);

    carry = 0;
    k = 0, i = len_a-1, j = len_b-1;
    for(; i >= 0 && j >= 0; j--, i--, k++) {
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


    if(carry != 0) c[k++] = carry + 48;
    c[k] = '\0';
    strrev(c);

}



void BIG_INT_MUL(char *x, char *y, char *t) {

    int i,j,k,C,r,xi,yi,Cs,m;
    C=0,Cs=0;

    for(i=0;; i++) if(x[i]=='\0') break;
    xi=i-1;

    for(i=0;; i++) if(y[i]=='\0') break;
    yi=i-1;

    for(i=0; i<502; i++) t[i]='0';

    for(j=0; yi>=0; yi--,j++) {

        for(i=0,k=xi; k>=0; k--,i++) {

            r= mul_s(x[k]-48,y[yi]-48,C);
            C=mul_c(x[k]-48,y[yi]-48,C);
            m=t[i+j];
            t[i+j]=sum_s(r,m-48,Cs)+48;
            Cs=sum_c(r,m-48,Cs);
        }

        t[i+j]=C+Cs+48;
        C=0;
        Cs=0;
    }

    for(k=i+j; k>0; k--) {
        if(t[k]!=48) {
            t[k+1]=0;
            break;
        }
    }

    t[k+1] = 0;
    strrev(t);
}



uint64 BIG_INT_DIV(char *a, uint64 b, char *c) {

    int la;
    int i,k=0,flag=0;
    uint64 temp=1,reminder;
    la=strlen(a);

    for(i=0; i<=la; i++) a[i] = a[i] - 48;

    temp = a[0];
    reminder = a[0];
    for(i=1; i<=la; i++) {
        if(b<=temp) {
            c[k++] = temp/b;
            temp = temp % b;
            reminder = temp;
            temp =temp*10 + a[i];
            flag=1;
        }
        else {
            reminder = temp;
            temp =temp*10 + a[i];
            if(flag==1) c[k++] = 0;
        }
    }

    for(i=0; i<k; i++) {
        c[i]=c[i]+48;
    }
    c[i]= '\0';
	if(i == 0){
		c[i] = '0'; c[1] = '\0';
	}
    return reminder;
}

/**************************Big Number End***************************/

//(t^a − 1)/(t^b − 1)



int main() {

	int t, a, b;
	char str_t[5000], str_a[5000], str_b[5000], up[5000], dwn[5000], tmp[5000];
	while(!(cin << t << a << b)){
		sprintf(str_t, "%d", t);
		sprintf(str_a, "%d", a);		
		sprintf(str_b, "%d", b);
		
		up[0] = '1', up[1] = '\0';
		REP(i, a){
			strcpy(tmp, up);
			BIG_INT_MUL(tmp, t, up);
		};		
		
		dwn[0] = '1'; dwm[1] = '\0';
		REP(i, b){
			strcpy(tmp, dwn);
			BIG_INT_MUL(tmp, t, dwn);
		};
		
		
		
	}
    return 0;
}
