/*
 * FILE: Krakovia-10925.cpp
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
 *    18 Feb 2017    New             1.0		AC
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




uint64 BIG_INT_DIV(char *a,uint64 b, char *c){

    int la;
    int i,k=0,flag=0;
    uint64 temp=1,reminder;
    la=strlen(a);

    for(i=0;i<=la;i++){
         a[i] = a[i] - 48;
    }

    temp = a[0];
    reminder = a[0];
    for(i=1;i<=la;i++){
         if(b<=temp){
             c[k++] = temp/b;
             temp = temp % b;
             reminder = temp;
             temp =temp*10 + a[i];
             flag=1;

         }
         else{
             reminder = temp;
             temp =temp*10 + a[i];
             if(flag==1)
                 c[k++] = 0;
         }
    }

    for(i=0;i<k;i++){
         c[i]=c[i]+48;
    }
    c[i]= '\0';
	if(i == 0){
		c[i] = '0'; c[1] = '\0';
	}
    return reminder;
}


/**************************Big Number End***************************/



int main() {
	
	int i, N, F, Case = 0;
	char a[250], c[250], b[250];
	
	while(cin >> N >> F){
		if(!N && !F) return 0;
		c[0] = '0'; c[1] = '\0';
		for(i = 0; i < N; i++){
			cin >> a;
			strcpy(b, c);
			BIG_INT_SUM(a, b, c);
		}
		strcpy(b, c);
		BIG_INT_DIV(b, F, a);
		cout << "Bill #" << ++Case << " costs " << c;
		cout << ": each friend should pay " << a << endl << endl;
	}
    return 0;
}

