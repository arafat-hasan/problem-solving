/*
 * FILE: B.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 26-11-17 22:43:54 (+06)
 * LAST MODIFIED: __last_modified
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 26-11-17     1.0         {{File Created}}
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
#define MAX             1000000000

////////////////////////// START HERE //////////////////////////

int binarysearch (int *array, int end, int key) {
    //array must be sorted, if key is found return 0 based index,
    //else -1;
    int start = 0, mid;
    end--;
    while (start <= end) {
        mid = (start + end) / 2;
        if (key == array[mid]) return mid;
        else if (key < array[mid]) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}

int numofdiv(int A, int B, int K) {
    int Fdiv = A % K == 0 ? A : A + (K - A % K);
    int Ldiv = B % K == 0 ? B : B - B % K;
    return (Ldiv - Fdiv) / K + 1;
}

int main() {
    __FastIO;
    int n, x, k, cnt = 0;
    cin >>  n >> x >> k;
    ll rng = x * k;
    if (rng > MAX) return !(cout << "0\n");
    vi v(n);
    rep(i, n) cin >> v[i];
    sort(all(v));
    std::vector<int>::iterator low, up;
    for (int i = 0; i < n; i++) {
        int Fdiv = v[i] % k == 0 ? v[i] : v[i] + (k - v[i] % k);
        int Ldiv = v[i] % k == 0 ? v[i] : v[i] - v[i] % k;
        debug2(Fdiv, Ldiv);
        low = std::lower_bound (v.begin(), v.end(), Fdiv);
        up = std::upper_bound (v.begin(), v.end(), Ldiv);
        debug2((int) (up - v.begin()), (int) (low  - v.begin()));
        cnt += (int) (up - v.begin())  - (int) (low  - v.begin()) + 1;
    }
    cout << cnt << endl;
    return 0;
}

/*int main() {*/
//    __FastIO;
//    int n, x, k, div, cnt = 0;
//    cin >>  n >> x >> k;
//    ll rng = x * k;
//    if (rng > MAX) return !(cout << "0\n");
//    vi v(n);
//    rep(i, n) cin >> v[i];
//    sort(all(v));
//    if (v[0] == v[(int) v.size() - 1]) return !(cout << n * n << endl);

//    for (int i = 0; i < n; i++) {
//        int j = (i == 0 ? 0 : v[i - 1] == v[i] ? 0 : i);
//        //int j = 0;
//        for (; j < n; j++) {
//            if (v[j] < v[i]) continue;
//            //if (v[j] - v[i] + 1 < rng) continue;
//            div = numofdiv(v[i], v[j], x);
//            if (div == k) cnt++;
//            if (div > k) break;
//        }
//    }
//    cout << cnt << endl;
//    return 0;
//}

