/*
 * FILE: 918C.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 29-01-18 21:21:16 (+06)
 * LAST MODIFIED: 29-01-18 22:26:58 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 29-01-18     1.0         {{File Created}}
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

string str;

bool isValid (int l, int r) {
    stack<char> stk, stk2;
    bool loop1 = true, loop2 = true;

    for (int i = l; i <= r; i++) {
        if (str[i] == '(') {
            stk.push (str[i]);
        } else if (str[i] == ')') {
            if (stk.empty() ) {
                loop1 = false;
                break;
            } else if (stk.top() == '(') stk.pop();
            else if (stk.top() == '?') stk.pop();
            else {
                loop1 = false;
                break;
            }
        } else if (str[i] == '?') {
            if (!stk.empty() ) stk.pop();
            else stk.push (str[i]);
        }
    }

    if (loop1 == true) {
        if (!stk.empty() ) loop1 = false;
    }

    for (int i = r; i >= l; i--) {
        if (str[i] == ')') {
            stk2.push (str[i]);
        } else if (str[i] == '(') {
            if (stk2.empty() ) {
                loop2 = false;
                break;
            } else if (stk2.top() == ')') stk2.pop();
            else if (stk2.top() == '?') stk2.pop();
            else {
                loop2 = false;
                break;
            }
        } else if (str[i] == '?') {
            if (!stk2.empty() ) stk2.pop();
            else stk2.push (str[i]);
        }
    }

    if (loop2 == true) {
        if (!stk2.empty() ) loop2 = false;
    }

    return (loop1 or loop2);
}

int main() {
    __FastIO;
    cin >> str;
    int sz = (int) str.size(), cnt = 0;

    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
            if (isValid (i, j) ) cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}


