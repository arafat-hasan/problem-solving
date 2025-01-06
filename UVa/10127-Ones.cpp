/*
 * FILE: Ones-10127.cpp
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
 *    22 Feb 2017    New             1.0        AC
 *
 */


//~ #include <iostream>
//~ #include <vector>
//~ #include <algorithm>
//~ #include <queue>
//~ #include <climits>
//~ #include <cmath>
//~ #include <cstring>
//~ #include <cstdio>
//~ #include <cstdlib>
//~ #include <iomanip>

//~ #define FileIn(file) freopen("input.txt", "r", stdin)
//~ #define FileOut(file) freopen("output.txt", "w", stdout)
//~ #define FOR(i, a, b) for (int i=a; i<=b; i++)
//~ #define ROF(i, b, a) for (int i=b; i>=a; i--)
//~ #define REP(i, n) for (int i=0; i<n; i++)
//~ #define Fill(ar, val) memset(ar, val, sizeof(ar))
//~ #define uint64 unsigned long long
//~ #define all(ar) ar.begin(), ar.end()
//~ #define pb push_back


//~ /*****************____________BIT_OPERATIONS____________****************/
//~ #define bit(n) (1 << (n)) //2^n
//~ //check ith bit of integer n, 0 or 1
//~ #define bitchk(n, i) ((n & (1 << i))? 1 : 0)
//~ #define bit_on(n, i) (n | (1 << i)) //set ith bit ON of the integer n
//~ #define bit_off(n, i) (n & ~(1 << i)) //set ith bit OFF of the intger n
//~ //toggle ith bit of integer n, set 0 if 1, set 1 if 0
//~ #define bit_toggle(n, i) (n ^ ( 1 << i))
//~ //set ith bit to x (x is bool, 1 or 0) of the integer n
//~ #define bit_setx(n, x, i) (n ^ ((-x ^ n) & (1 << i)))


//~ #define nl cout << endl;
//~ #define lck cout << "______________" << endl;

//~ typedef long long ll;
//~ using namespace std;

//~ uint64 big_int_div(char *a, uint64 b, char *c) {

//~ int la;
//~ int i,k=0,flag=0;
//~ uint64 temp=1,reminder;
//~ la=strlen(a);

//~ for(i=0; i<=la; i++) a[i] = a[i] - 48;

//~ temp = a[0];
//~ reminder = a[0];
//~ for(i=1; i<=la; i++) {
//~ if(b<=temp) {
//~ c[k++] = temp/b;
//~ temp = temp % b;
//~ reminder = temp;
//~ temp =temp*10 + a[i];
//~ flag=1;
//~ }
//~ else {
//~ reminder = temp;
//~ temp =temp*10 + a[i];
//~ if(flag==1) c[k++] = 0;
//~ }
//~ }

//~ for(i=0; i<k; i++) {
//~ c[i]=c[i]+48;
//~ }
//~ c[i]= '\0';
//~ if(i == 0) {
//~ c[i] = '0';
//~ c[1] = '\0';
//~ }
//~ return reminder;
//~ }


//~ int main() {

//~ uint64 n;
//~ char a[9000], b[9000], c[9000];
//~ while(cin >> n){
//~ memset(a, 0, sizeof(a));
//~ a[0] = '1';
//~ for(int i = 2; i < 8999; i++){
//~ a[i-1] = '1', a[i] = '\0';
//~ for(int j = 0; j <= i; j++) c[j] = a[j];
//~ if(big_int_div(c, n, b) == 0){
//~ cout << i << endl;
//~ break;
//~ }
//~ }
//~ }

//~ return 0;
//~ }





#include <stdio.h>

int main() {

    int  count, g, n;

    while(scanf("%d",&n) == 1) {
        count=1;
        g=1;
        while(g%n!=0 && count++) g = (g * 10 + 1) % n;
        printf("%d\n", count);
    }

    return 0;
}
