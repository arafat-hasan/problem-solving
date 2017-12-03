/*
 * FILE: C.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 02-12-17 21:29:45 (+06)
 * LAST MODIFIED: 03-12-17 01:54:16 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 02-12-17     1.0         {{File Created}}
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
#define MAX             10000005

////////////////////////// START HERE //////////////////////////

string str("What are you doing at the end of the world? Are you busy? Will you save us?");
string f = "What are you doing while sending ";
string l = "? Are you busy? Will you send ";
int FH = (int) f.size();
int LH = (int) l.size();

ll presize(ll n) {
    //debug2("## ", n);
    if (n < 0) return 0;
    if (n == 0) return (ll) str.size();
    return presize(n - 1) * 2 + (ll) f.size() + (ll)l.size();
}

char fun(ll n, ll k) {

    ll prvsz = presize(n - 1);
    //debug3(n, k, prvsz);
    if (n == 0) return str[k];

    if (k < FH) {
        return f[k];
    } else if (k == FH) {
        return '\"';
    } else if (k > FH and k < prvsz + FH + 1) {
        return fun(n - 1, k - FH - 1 );
    } else if (k == prvsz + FH + 1) {
        return '\"';
    } else if (k > prvsz + FH + 1 and k < FH + prvsz + LH + 2) {
        return l[k - FH - prvsz - 2];
    } else if (k == FH + prvsz + LH + 2) {
        return '\"';
    } else if (k > FH + prvsz + LH  + 2 and k < FH + prvsz + LH + prvsz + 3) {
        return fun(n - 1, k - (FH + prvsz + LH + 3));
    } else if (k == FH + prvsz + LH + prvsz + 3) {
        return '\"';
    } else {
        return '.';
    }
}

int main() {
    //__FastIO;

    ll q, n, k;
    char ch;
    cin >> q;
    rep(i, q) {
        cin >> n >> k; k--;
        ch = fun(n, k);
        //debug2(k + 1, ch);
        cout << ch;
    }
    cout << endl;
    return 0;
}

