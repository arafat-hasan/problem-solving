/*
 * FILE: CHEFPRMS.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK: https://www.codechef.com/SNCKQL19/problems/CHEFPRMS
 *
 * DATE CREATED: 13-10-18 14:30:43 (+06)
 * LAST MODIFIED: 13-10-18 14:44:43 (+06)
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

bool isPrime (int num) {
    if (num == 2) return true;

    if (num < 2 or num % 2 == 0) return false;

    int i, root = (int) sqrt (num);

    for (i = 3; i <= root; i += 2)
        if (num % i == 0) return false;

    return true;
}

int main() {
    //_FastIO;
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        //debug1 (n);
        bool ans = false;
        //int firstL = 0, firstR = 0, secL = 0, secR = 0;

        for (int left = 6; left < n; left++) {
            int right = n - left;
            bool flag1 = false, flag2 = false;

            for (int i = 2; i <= left / 2; i++) {
                if (left % i == 0 and isPrime (i) and isPrime (left / i) \
                    and i != left / i) {
                    flag1 = true;
                    //firstL = i, firstR = left / i;
                    break;
                }
            }

            for (int i = 2; i <= right / 2; i++) {
                if (right % i == 0 and isPrime (i) and isPrime (right / i)\
                    and i != right / i) {
                    flag2 = true;
                    //secL = i, secR = right / i;
                    break;
                }
            }

            if (flag1 and flag2) {
                ans = true;
                break;
            }
        }

        //cerr << firstL << " * " << firstR << " + " << secL << " * " << secR << endl;
        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}


