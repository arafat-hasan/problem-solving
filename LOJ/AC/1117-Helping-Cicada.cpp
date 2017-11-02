/*
 * FILE: /media/Softwares/Programming/ACM/LOJ/AC/1117-Helping-Cicada.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 02-11-17 01:53:19 (+06)
 * LAST MODIFIED: 02-11-17 02:25:59 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 02-11-17     1.0         {{File Created}}
 *
 *
 *                 ██╗███████╗███╗   ██╗██╗███╗   ██╗
 *                 ██║██╔════╝████╗  ██║██║████╗  ██║
 *                 ██║█████╗  ██╔██╗ ██║██║██╔██╗ ██║
 *            ██   ██║██╔══╝  ██║╚██╗██║██║██║╚██╗██║
 *            ╚█████╔╝███████╗██║ ╚████║██║██║ ╚████║
 *             ╚════╝ ╚══════╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═══╝
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
//#include <unordered_map> // -std=c++11 not set in LOJ
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

//////////////// BIT SET //////////////

// 2^n
#define bit(n)              (1 << (n))
// Check ith bit of integer n, 0 or 1
#define bitchk(n, i)        ((n & (1 << (i)))? 1 : 0)
//set ith bit ON of the integer n
#define bit_on(n, i)        n = (n | (1 << (i)))
//set ith bit OFF of the intger n
#define bit_off(n, i)       n = (n & ~(1 << (i)))
// Toggle ith bit of integer n, set 0 if 1, set 1 if 0
#define bit_toggle(n, i)    n = (n ^ ( 1 << (i)))
// Set ith bit to x (x is bool, 1 or 0) of the integer n
#define bit_setx(n, x, i)   n = (n ^ ((-(x) ^ n) & (1 << (i))))

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             10000005

////////////////////////// START HERE //////////////////////////

ll lcm(ll a, ll b) {
    return ((a * b) / __gcd(a, b));
}

int main() {
    __FastIO;
    ll tc, n, m, arr[16], bits, lm, cnt, cs = 0;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        rep(i, m) cin >> arr[i];
        bits = bit(m);
        ll ans = 0;
        for (int i = 1; i <= bits; i++) {
            cnt = 0;
            lm = 1;
            for (int j = 0; j < m; j++) {
                if (bitchk(i, j)) {
                    cnt++;
                    lm = lcm(lm, arr[j]);
                }
            }
            (cnt & 1) ? ans -= n / lm : ans += n / lm;
        }
        cout << "Case " << ++cs << ": " << ans << '\n';
    }
    return 0;
}

