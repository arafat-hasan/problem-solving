/*
 * FILE: Simply_Emirp-10235.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK: https://uva.onlinejudge.org/external/102/10235.pdf
 *
 * Description:
 *
 *
 *   DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    29 Jan 2017    New             1.0		Completed, AC
 *    13 Mar 2017    Changed             1.1        AC
 *
 *
 */


//ver 1.0
//time 0.860
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <cmath>
// 
// 
// 
// #define pf cout << n << 
// #define nl <<endl;
// #define FOR(i, a, b) for (int i=a; i<=b; i++)
// #define REP(i, n) for (int i=0; i<n; i++)
// #define Fill(ar, val) memset(ar, val, sizeof(ar))
// #define uint64 unsigned long long
// #define int64 long long
// #define all(ar) ar.begin(), ar.end()
// #define pb push_back
// #define bit(n) (1<<(n))
// #define Last(i) (i & -i)
// 
// #define maxS 100000000
// 
// using namespace std;
// 
// void sieve(int n);
// int reversDigits(int num);
// int  primelst[maxS]; //for sieve
// 
// 
// 
// int main() {
// 
// 	int n;
//     sieve(maxS);
// 
//     while(cin >> n) {
//         if(!primelst[n] && !primelst[reversDigits(n)] && n != reversDigits(n))pf " is emirp." nl
//         else if(!primelst[n]) pf " is prime." nl
//         else pf " is not prime." nl
//     }
// 
// 
//     return 0;
// }
// 
// 
// void sieve(int n) {
// 
//     int i,j;
//     double root=sqrt(n);
// 
//     primelst[0]=primelst[1]=1;
// 
//     for(i=4; i<n; i+=2)
//         primelst[i]=1;
// 
//     for(i=3, j=0; i<=root; i+=2) {
//         if(!primelst[i]) {
//             for(j=i*i; j<n; j+=2*i)
//                 primelst[j]=1;
//         }
//     }
// }
// 
// int reversDigits(int num) {
//     int rev_num = 0;
//     while(num > 0) {
//         rev_num = rev_num*10 + num%10;
//         num = num/10;
//     }
//     return rev_num;
// }
// 
// 
// 


//ver 1.1
//time 0.000s
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
#define ROF(i, b, a) for (int i=b; i>=a; i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define uint64 unsigned long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)


/*****************____________BIT_OPERATIONS____________****************/
#define bit(n) (1 << (n)) //2^n
//check ith bit of integer n, 0 or 1
#define bitchk(n, i) ((n & (1 << i))? 1 : 0)
#define bit_on(n, i) (n | (1 << i)) //set ith bit ON of the integer n
#define bit_off(n, i) (n & ~(1 << i)) //set ith bit OFF of the intger n
//toggle ith bit of integer n, set 0 if 1, set 1 if 0
#define bit_toggle(n, i) (n ^ ( 1 << i))
//set ith bit to x (x is bool, 1 or 0) of the integer n
#define bit_setx(n, x, i) (n ^ ((-x ^ n) & (1 << i)))


#define nl cout << endl
#define lck cout << "#########" << endl
#define MAX 1000000

typedef long long ll;
using namespace std;
int primelst[MAX];

void sieve(int n) {

    int i,j;
    double root = sqrt(n);
    primelst[0] = primelst[1] = 1;

    for(i = 4; i < n; i += 2)
        primelst[i] = 1;

    for(i = 3, j = 0; i <= root; i += 2) {
        if(!primelst[i]) {
            for(j = i*i; j < n; j += 2*i)
                primelst[j] = 1;
        }
    }
}

int main() {

    std::ios::sync_with_stdio(false);

    int n, tmp, reverse;
    sieve(MAX);
    while(cin >> n){
        if(primelst[n]) cout << n << " is not prime.\n";
        else{
            tmp = n;
            reverse = 0;
            while(tmp > 0){
                reverse = (reverse*10) + tmp % 10;
                tmp /= 10;
            }
            if(primelst[reverse] || n==reverse) cout << n << " is prime.\n";
            else cout << n << " is emirp.\n";
        }
    }

    return 0;
}


