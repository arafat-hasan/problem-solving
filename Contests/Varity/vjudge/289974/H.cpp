/*
 * FILE: {H.cpp}
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: {{long_date}}
 * LAST MODIFIED: 27-03-19 23:05:00 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * {{short_date}}     1.0         {{File Created}}
 *
 *               _/  _/_/_/_/  _/      _/  _/_/_/  _/      _/
 *              _/  _/        _/_/    _/    _/    _/_/    _/
 *             _/  _/_/_/    _/  _/  _/    _/    _/  _/  _/
 *      _/    _/  _/        _/    _/_/    _/    _/    _/_/
 *       _/_/    _/_/_/_/  _/      _/  _/_/_/  _/      _/
 */

///////////////////////////////////////////////////////////////////////

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
#include <unordered_map>
#include <queue>
#include <deque>
#include <vector>
#include <tuple>
#include <iterator> // std::istream_iterator
#include <stdint.h> //uint32_t
#include <functional>
#include <bitset>
#include <unistd.h> // unsigned int sleep(unsigned int seconds);

using namespace std;

typedef long long           ll;
typedef double              lf;
typedef long double         llf;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef vector<pii>         vpii;
typedef vector<int>         vi;
typedef vector<long long>   vl;

#define _USE_MATH_DEFINES

#define _FastIO        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define forr(i, a, b)   for (__typeof (a) i = (a); i <= (b); i++)
#define rof(i, b, a)    for (__typeof (a) i = (b); i >= (a); i--)
#define rep(i, n)       for (__typeof (n) i = 0; i < (n); i++)
#define forit(i, s)     for (__typeof ((s).end()) i = (s).begin(); i != (s).end(); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(a, val)    memset((a), (val), sizeof((a)))
#define clr(a)          memset((a), 0, sizeof((a)))
#define sz(a)           (int) a.size()

#define pb              push_back

#ifndef ONLINE_JUDGE
    #define nl              cerr << '\n'
    #define sp              cerr << ' '
    #define ckk             cerr << "###############\n"
    #define debug1(x)       cerr << #x << ": " << (x) << '\n'
    #define debug2(x, y)    cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << '\n'
    #define debug3(x, y, z) cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << '\t' << #z << ": " << (z) << '\n'
#else
    #define nl
    #define sp
    #define ckk
    #define debug1(x)
    #define debug2(x, y)
    #define debug3(x, y, z)
#endif

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             10000007 //1e7+7

////////////////////////// START HERE //////////////////////////


int dp[1010][1010];
string str1, str2, str3;

int lcs (string &X, string &Y, int m, int n ) {
    if (m == 0 || n == 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    if (X[m - 1] == Y[n - 1])
        return dp[m][n] = 1 + lcs (X, Y, m - 1, n - 1);
    else
        return dp[m][n] = max (lcs (X, Y, m, n - 1), lcs (X, Y, m - 1, n) );
}


// dp array needed, last to first
string lcsAns; // store lcs here
string lcs_print (string X, string Y, int m, int n) {
    if (m == -1 or n == -1) {
        reverse (all (lcsAns) );
        return lcsAns;
    }

    if (X[m - 1] == Y[n - 1]) {
        lcsAns += X[m - 1];
        lcs_print (X, Y, m - 1, n - 1);

    } else {
        if (dp[m - 1][n] > dp[m][n - 1]) lcs_print (X, Y, m - 1, n);
        else lcs_print (X, Y, m, n - 1);
    }

    return lcsAns;
}

int main() {
    _FastIO;
    int t, cs = 0;
    cin >> t;

    while (t--) {
        cin.ignore();
        cin >> str1 >> str2 >> str3;
        fill (dp, -1);
        lcsAns.clear();
        lcs (str1, str2, (int) str1.size(), (int) str2.size());
        string lc = lcs_print (str1, str2, (int) str1.size(), (int) str2.size());
        fill (dp, -1);
        int sec = lcs (lc, str3, (int) lc.size(), (int) str3.size());
        cout << "Case " << ++cs << ": " << sec << endl;
    }

    return 0;
}
