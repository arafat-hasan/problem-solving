/*
 * FILE: 938C.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 16-02-18 22:09:31 (+06)
 * LAST MODIFIED: 17-02-18 01:26:50 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 16-02-18     1.0         {{File Created}}
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

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define forr(i, a, b)   for (__typeof (a) i = (a); i <= (b); i++)
#define rof(i, b, a)    for (__typeof (a) i = (b); i >= (a); i--)
#define rep(i, n)       for (__typeof (n) i = 0; i < (n); i++)
#define forit(i, s)     for (__typeof ((s).end()) i = (s).begin(); i != (s).end(); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset((ar), (val), sizeof((ar)))
#define clr(a)          memset((a), 0, sizeof((a)))
#define sz(a)           (int) a.size()

#define pb              push_back

#ifndef ONLINE_JUDGE
    #define nl              cerr << '\n';
    #define sp              cerr << ' ';
    #define ckk             cerr << "###############\n"
    #define debug1(x)       cerr << #x << ": " << (x) << endl
    #define debug2(x, y)    cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << endl
    #define debug3(x, y, z) cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << '\t' << #z << ": " << (z) << endl
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

bool chk (int n, int m, int x) {
    int tmp = n / m;
    tmp = tmp * tmp;
    tmp = (n * n) - tmp;
    return tmp == x;
}

int main() {
    //__FastIO;
    int t, x;
    int n = 0, m = 0;
    cin >> t;

    while (t--) {
        //for (int k = 1; k < 100000; k++) {
        cin >> x;
        //x = k;
        //cout << x << ' ';
        int root = (int) sqrt (x) - 3;
        root = (root < 1 ? 1 : root);

        while ( (root * root) < x) root++;

        //debug2 (x, root);
        bool fl = false;

        for (int i = 0; i < 50000; i++, root++) {
upore:
            int borgo = root * root;
            int number_of_zero = borgo - x;
            int sqrt_of_number_of_zero = (int) sqrt (number_of_zero) - 3;
            //debug3 (borgo, number_of_zero,  sqrt_of_number_of_zero);
            sqrt_of_number_of_zero = (sqrt_of_number_of_zero < 1 ? 1 :
                                      sqrt_of_number_of_zero);

            while ( (sqrt_of_number_of_zero * sqrt_of_number_of_zero) < number_of_zero)
                sqrt_of_number_of_zero++;

            //debug3 (root, number_of_zero,  sqrt_of_number_of_zero);

            if ( (sqrt_of_number_of_zero *  sqrt_of_number_of_zero) > number_of_zero)
                continue;

            //ckk;

            for (int j = 1; j <= 1000; j++) {
                int tmp = root / j;
                //debug2 (tmp, sqrt_of_number_of_zero);

                if (tmp == sqrt_of_number_of_zero) {
                    n = root;
                    m = j;
                    bool check = chk (n, m, x);

                    if (check == false) {
                        root++;
                        goto upore;
                    }

                    fl = true;
                    break;
                }
            }

            if (fl) break;
        }

        if (fl)
            cout << n << ' ' << m << '\n';
        else cout << "-1\n";
    }

    //}
    return 0;
}


