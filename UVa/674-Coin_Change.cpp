/*
 * FILE: Coin_Change-674.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK: https://uva.onlinejudge.org/external/6/674.pdf
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    20 Apr 2017    New             1.0        AC
 *
 */


/*
//     ___          ___           ___                       ___
//    /  /\        /  /\         /__/\        ___          /__/\
//   /  /:/       /  /:/_        \  \:\      /  /\         \  \:\
//  /__/::\      /  /:/ /\        \  \:\    /  /:/          \  \:\
//  \__\/\:\    /  /:/ /:/_   _____\__\:\  /__/::\      _____\__\:\
//     \  \:\  /__/:/ /:/ /\ /__/::::::::\ \__\/\:\__  /__/::::::::\
//      \__\:\ \  \:\/:/ /:/ \  \:\~~\~~\/    \  \:\/\ \  \:\~~\~~\/
//      /  /:/  \  \::/ /:/   \  \:\  ~~~      \__\::/  \  \:\  ~~~
//     /__/:/    \  \:\/:/     \  \:\          /__/:/    \  \:\
//     \__\/      \  \::/       \  \:\         \__\/      \  \:\
//                 \__\/         \__\/                     \__\/
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
#include <map>
#include <set>

typedef long long ll;
typedef double lf;


#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
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
#define sq(a) a * a
#define INF 2147483646


#define sfll(a) scanf("%lld", &a)
#define pfll(a) printf("%lld", a)
#define sflf(a) scanf("%lf", &a)
#define pflf(a) printf("%lf", a)
#define sff(a) scanf("%f", &a)
#define pff(a) printf("%f", a)
#define sf(a) scanf("%d", &a)
#define pf(a) printf("%d", a)
#define ln cout << '\n';
#define sp cout << ' ';
#define chk cout << "##########\n"

using namespace std;


//Accepted 0.00s
int coin[] = {1, 5, 10, 25, 50};
int dp[7500];

int main(){
    __FastIO;
    int n; 
    REP(i, 7495) dp[i] = 1;
    FOR(i, 1, 4){
        FOR(j, coin[i], 7495){
            dp[j] += dp[j-coin[i]];
        }
    }
    while(cin >> n)
        cout << dp[n] << '\n';

    return 0;
}



//Accepted, 0.010s
// int coin[] = {1, 5, 10, 25, 50};
// int make, j = 0;
// int dp[7500][5];
// int fun(int i, int n) {
//     if (i > 4) {
//         if (n == 0) return 1;
//         return 0;
//     }
//     if(dp[n][i] != -1) return dp[n][i];
//     int ret1 = 0, ret2 = 0;
//     if (n - coin[i] >= 0) ret1 = fun(i, n - coin[i]);
//     ret2 = fun(i + 1, n);
//     return dp[n][i] = ret1 + ret2;
//     
// }
// 
// 
// int main() {
// 
//     std::ios_base::sync_with_stdio(false); cin.tie(0);
//     memset(dp, -1, sizeof(dp));
//     fun(0, 7495);
//     while (cin >> make) {
//         cout << dp[make][0] << '\n';
//     }
//     return 0;
// }
