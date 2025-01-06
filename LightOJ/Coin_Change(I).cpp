/*
 * FILE: Coin_Change(I).cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK: http://lightoj.com/volume_showproblem.php?problem=1231
 *
 * DATE CREATED: 29-04-17 17:21:49 (+06)
 * LAST MODIFIED: 20-05-17 16:05:23 (+06)
 *
 * DESCRIPTION: DP Problem
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 29-04-17     1.0         File Created
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
#include <climits>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <utility>
#include <sstream>
#include <algorithm>
#include <stack>
#include <set>
#include <list>
#include <map>
#include <queue>
#include <vector>

typedef long long ll;
typedef double lf;

#define ull unsigned long long

#define FileIn(file) freopen("input.txt", "r", stdin)
#define FileOut(file) freopen("output.txt", "w", stdout)
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)

#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define ROF(i, b, a) for (int i=b; i>=a; i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define ALL(ar) ar.begin(), ar.end()
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define clr(a) memset(a, 0, sizeof a)
#define sfll(a) scanf("%lld", &a)
#define pfll(a) printf("%lld", a)
#define sflf(a) scanf("%lf", &a)
#define pflf(a) printf("%lf", a)
#define sff(a) scanf("%f", &a)
#define pff(a) printf("%f", a)
#define sf(a) scanf("%d", &a)
#define pf(a) printf("%d", a)
#define NL cout << '\n';
#define SP cout << ' ';
#define CHK cout << "##########\n"
#define DEBUG1(x) cout << #x << ": " << x << endl
#define DEBUG2(x, y) cout << #x << ": " << x << "\t" << #y << ": " << y << endl
#define DEBUG3(x, y, z) cout << #x << ": " << x << "\t" << #y << ": " << y << "\t" << #z << ": " << z << endl

#define PB push_back
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)
#define sq(a) a * a
#define INF 2147483646
#define MOD 100000007
#define PI acos(-1.0)
#define MAX 100000000

using namespace std;

/********************* Code starts here ************************/









int coin[50];
int coincnt[50];
int j = 0;
int dp[2000][51];
int n, k;
int fun(int i, int make) {
    //DEBUG3(i, taken, make);
    //if (taken < 0) {
    //    if (make + coin[i] == 0) {
    //        cout << "$$$\n";
    //        return 1;
    //    }
    //    CHK;
    //    return 0;
    //}
    if (make < 0) {
        return 0;
    }

    if (i >= n) {
        if (make == 0) {
            //cout << "$$$\n";
            return 1;
        }
        //cout << "()()()()()\n";
        return 0;
    }

    if (dp[make][i] != -1) {
        //cout << "{{{{{{\n";
        return dp[make][i];
    }
    int ret1 = 0, ret2 = 0;
    if (make - coin[i] >= 0) {
        ret1 = fun(i, make - coin[i]);
    }

    //if (taken == 0) {
    //if(make == 0) ret1 = 1;
    //}
    //cout << "***\n";
    ret2 = fun(i + 1,  make);
    //DEBUG2(ret1, ret2);
    //DEBUG3(taken, make, i);
    return dp[make][i] = (ret1 + ret2);
    //return dp[taken][make][i];
    //return ret1 + ret2;
}


int main() {
    __FastIO;
    int T, cs = 0;
    cin >> T;
    while (T--) {
        Fill(dp, -1);
        cin >> n >> k;
        REP(i, n) cin >> coin[i];
        REP(i, n) cin >> coincnt[i];
        //DEBUG1(n);
        cout << "Case " << ++cs << ": ";
        cout << fun(0, k) % MOD; 
        NL;
        //NL;NL;NL;
    }
    return 0;
}

































//int coin[50];
//int coincnt[50];
//int make, j = 0;
//int dp[51][3000][21];
//int n, k;
//int fun(int i, int taken, int make) {
//    //DEBUG3(i, taken, make);
//    if (taken < 0) {
//        if (make + coin[i] == 0) {
//            //cout << "$$$\n";
//            return 1;
//        }
//        //CHK;
//        return 0;
//    }
//    if (i >= n) {
//        if (make == 0) {
//            //cout << "$$$\n";
//            return 1;
//        }
//        //cout << "()()()()()\n";
//        return 0;
//    }
//    if (dp[taken][make][i] != -1) {
//        //cout << "{{{{{{\n";
//        return dp[taken][make][i] % MOD;
//    }
//    int ret1 = 0, ret2 = 0;
//    if (make - coin[i] >= 0 && taken >= 0) {
//        ret1 = fun(i, taken - 1, make - coin[i]) % MOD;
//    }

//    //if (taken == 0) {
//    //if(make == 0) ret1 = 1;
//    //}
//    //cout << "***\n";
//    ret2 = fun(i + 1, coincnt[i + 1],  make) % MOD;
//    //DEBUG2(ret1, ret2);
//    //DEBUG3(taken, make, i);
//    return dp[taken][make][i] = (ret1 + ret2) % MOD;
//    //return dp[taken][make][i];
//    //return ret1 + ret2;
//}


//int main() {
//    __FastIO;
//    int T, cs = 0;
//    cin >> T;
//    while (T--) {
//        Fill(dp, -1);
//        cin >> n >> k;
//        REP(i, n) cin >> coin[i];
//        REP(i, n) cin >> coincnt[i];
//        //DEBUG1(n);
//        cout << "Case " << ++cs << ": ";
//        cout << fun(0, coincnt[0], k) % MOD;
//        NL;
//        //NL;NL;NL;
//    }
//    return 0;
//}










//TLE, OK, Correct solve
//int coin[50];
//int coincnt[50];
//int j = 0;
//int dp[25][2000][51];
//int n, k;
//int fun(int i, int taken, int make) {
//    //DEBUG3(i, taken, make);
//    //if (taken < 0) {
//    //    if (make + coin[i] == 0) {
//    //        cout << "$$$\n";
//    //        return 1;
//    //    }
//    //    CHK;
//    //    return 0;
//    //}
//    if (make < 0) {
//        return 0;
//    }

//    if (i >= n) {
//        if (make == 0) {
//            //cout << "$$$\n";
//            return 1;
//        }
//        //cout << "()()()()()\n";
//        return 0;
//    }

//    if (dp[taken][make][i] != -1) {
//        //cout << "{{{{{{\n";
//        return dp[taken][make][i];
//    }
//    int ret1 = 0, ret2 = 0;
//    if (make - coin[i] >= 0 && taken > 0) {
//        ret1 = fun(i, taken - 1, make - coin[i]);
//    }

//    //if (taken == 0) {
//    //if(make == 0) ret1 = 1;
//    //}
//    //cout << "***\n";
//    ret2 = fun(i + 1, coincnt[i + 1],  make);
//    //DEBUG2(ret1, ret2);
//    //DEBUG3(taken, make, i);
//    return dp[taken][make][i] = (ret1 + ret2);
//    //return dp[taken][make][i];
//    //return ret1 + ret2;
//}


//int main() {
//    __FastIO;
//    int T, cs = 0;
//    cin >> T;
//    while (T--) {
//        Fill(dp, -1);
//        cin >> n >> k;
//        REP(i, n) cin >> coin[i];
//        REP(i, n) cin >> coincnt[i];
//        //DEBUG1(n);
//        cout << "Case " << ++cs << ": ";
//        cout << fun(0, coincnt[0], k) % MOD; 
//        NL;
//        //NL;NL;NL;
//    }
//    return 0;
//}




//using namespace std;

//typedef long long sll;
//#define sfl(x) scanf("%lld",&x)
//#define pfl(x) printf("%lld\n",x)
//#define mod 100000007

//int n , K;
//int dp[55][1004];
//int coin[55];
//int mtake[55];

//int change (int i , int ase) {
// if (i >= n) {
//  if (ase == K) return 1;
//  else return 0;
// }
// if (ase > K) return 0;
// //if (ase == K) return 1;
// if (dp[i][ase] != -1) return dp[i][ase];
// int tt = 0;
// for (int ii = 1; ii <= mtake[i]; ii++) {
//  if (ase + coin[i] * ii <= K) 
//  tt += change (i + 1 , ase + coin[i] * ii) % mod;
//  else break; 
// }
// tt += change (i + 1 , ase) % mod;
// dp[i][ase] = tt % mod;
// return dp[i][ase];
//}

//int main () {
// int T; scanf ("%d" , &T); 
// int i; 
// for (i = 1; i <= T; i++) {
//  memset (dp , -1 , sizeof (dp));
//  scanf ("%d%d" , &n , &K);
//  for (int ii = 0; ii < n; ii++) 
//      scanf ("%d" , coin + ii);
//     for (int ii = 0; ii < n; ii++)
//         scanf ("%d" , mtake + ii);
//     printf ("Case %d: %d\n" , i , change (0 , 0) % mod);
// }
//}
