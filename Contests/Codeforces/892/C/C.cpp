/*
 * FILE: C.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 17-11-17 21:33:26 (+06)
 * LAST MODIFIED: 17-11-17 22:00:21 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 17-11-17     1.0         {{File Created}}
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

int arr[2005];

int findGCD(int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++)
        result = __gcd(arr[i], result);
    return result;
}


int main() {
    __FastIO;
    int n;
    cin >> n;
    rep(i, n) cin >> arr[i];
    int allgcd = findGCD(n), cnt = 0, tmpgcd;
    //debug1(allgcd);
    if (allgcd != 1) return !(cout << "-1\n");
    //int ttt = 30;
    //bool no = false;
    bool gcdone = false;
    for (int i = 0; i < n - 1; i++) {
        //if (!no) {
        //    rep(j, n) cout << arr[j] << ' ';
        //    debug3(arr[i], arr[i + 1], i);
        //}
        //no = false;

        tmpgcd = __gcd(arr[i], arr[i + 1]);
        if (tmpgcd == 1) gcdone = false;
        if (tmpgcd != 1 and i != n - 2 and gcdone != false) continue;

        if (arr[i] != tmpgcd) arr[i] = tmpgcd, i--;
        else if (arr[i + 1] != tmpgcd) arr[i + 1] = tmpgcd, i--;
        else cnt--;
        gcdone = true;

        cnt++;

        //debug3(i, tmpgcd, cnt);
        //debug2(arr[])
        //nl;

        //if (ttt-- < 0) exit(1);
        if (i == n - 2) {
            bool flag = true;
            rep(j, n) {
                if (arr[j] != 1) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) break;
            i = -1;
        }
    }

    cout << cnt << endl;

    return 0;
}

