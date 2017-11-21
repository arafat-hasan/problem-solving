/*
 * FILE: dp_100.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK: https://uva.onlinejudge.org/external/1/100.pdf
 *
 * DATE CREATED: 16-11-17 18:14:47 (+06)
 * LAST MODIFIED: 16-11-17 21:49:26 (+06)
 *
 * DESCRIPTION: Dynamic Programming
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 16-11-17     1.0         File Created, Accepted
 *
 *
 *                 _/  _/_/_/_/  _/      _/  _/_/_/  _/      _/
 *                _/  _/        _/_/    _/    _/    _/_/    _/
 *               _/  _/_/_/    _/  _/  _/    _/    _/  _/  _/
 *        _/    _/  _/        _/    _/_/    _/    _/    _/_/
 *         _/_/    _/_/_/_/  _/      _/  _/_/_/  _/      _/
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
#include <stdint.h> //uint32_t
#include <functional>
#include <bitset>

using namespace std;

typedef long long           ll;
typedef double              lf;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef vector<pii>         vpii;
typedef vector<int>         vi;

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)   for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "##########\n"
#define pb              push_back
#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAXX            10000002
#define MAX             1000050

////////////////////////// START HERE //////////////////////////

int dp[MAXX];
int ST[30][MAX];

class Sparse_table {
public:
    Sparse_table(int N) {
        for (int i = 0; i < N; i++) ST[0][i] = i;

        for (int k = 1; (1 << k) < N; k++) {
            for (int i = 0; i + (1 << k) <= N; i++) {
                int x = ST[k - 1][i];
                int y = ST[k - 1][i + (1 << (k - 1))];
                ST[k][i] = dp[x] >= dp[y] ? x : y;
            }
        }
    }

    int RMQ(int i, int j) {
        if (i == j) return i;
        int k = (int) log2(j - i);
        int x = ST[k][i];
        int y = ST[k][j - (1 << k) + 1];
        return dp[x] >= dp[y] ? x : y;
    }
};

int fun(ll n) {
    if (n >= MAXX) {
        if (n & 1) return 1 + fun(3 * n + 1);
        return 1 + fun(n / 2);
    }
    if (dp[n] != 0) return dp[n];
    if (n == 1) return 1;
    if (n & 1) return dp[n] = (1 + fun(3 * n + 1));
    return dp[n] = (1 + fun(n / 2));
}

int main() {
    __FastIO;
    for (int i = 1; i < MAX; i++) {
        if (dp[i] == 0)
            dp[i] = fun(i);
    }

    int i, j, max, first, second;
    Sparse_table sparse_table(MAX);

    while (cin >> i >> j) {
        first = i; second = j;
        if (i > j) swap(i, j);
        max = sparse_table.RMQ(i, j);

        cout << first << ' ' << second << ' ' << dp[max] << '\n';
    }

    return 0;
}

