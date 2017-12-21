/*
 * FILE: B.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 17-12-17 12:49:48 (+06)
 * LAST MODIFIED: 17-12-17 13:28:22 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 17-12-17     1.0         {{File Created}}
 *
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

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)   for (__typeof (a) i = a; i <= b; i++)
#define rof(i, b, a)    for (__typeof (a) i = b; i >= a; i--)
#define rep(i, n)       for (__typeof (n) i = 0; i < n; i++)
#define forit(i, s)     for (__typeof ((s).end()) i = (s).begin(); i != (s).end(); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "###############\n"
#define pb              push_back
#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             10000007 //10e7

////////////////////////// START HERE //////////////////////////

int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //Not Leap Year
int monthL[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //Leap Year

int main() {
    __FastIO;
    int n, arr[30];
    cin >> n;
    bool leap = false;
    rep (i, n) cin >> arr[i], arr[i] == 29 ? leap = true : leap;
    vector<int> v, vL;
    int j = 0;

    for (int i = 0; i < 24; i++) {
        if (j == 12) j = 0;

        v.pb (month[j++]);
    }

    //for (int i = 0; i < (int) v.size(); i++) {
    //    int tmp = i;

    //    for (j = 0; j < n; j++) {
    //        if (v[tmp] != arr[j]) {
    //            break;
    //        }

    //        tmp++;
    //    }

    //    if (j == n) {
    //        cout << "YES\n";
    //        return 0;
    //    }
    //}

    if (leap)
        for (int i = 0; i < 12; i++) {
            v.pb (monthL[i]);
        }

    j = 0;

    for (int i = 0; i < 24; i++) {
        if (j == 12) j = 0;

        v.pb (month[j++]);
    }

    for (int i = 0; i < (int) v.size(); i++) {
        int tmp = i;

        for (j = 0; j < n; j++) {
            //debug2 (v[tmp], arr[j]);
            if (v[tmp] != arr[j]) {
                break;
            }

            tmp++;
        }

        //debug2 (n, j);

        if (j == n) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}


