/*
 * FILE: 1082-Array_Queries.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: http://www.lightoj.com/volume_showproblem.php?problem=1082
 *
 * DATE CREATED: 30-03-20 18:33:57 (+06)
 * LAST MODIFIED: 31-03-20 19:46:34 (+06)
 *
 * VERDICT: Accepetd
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 30-03-20     1.0         Deleted code is debugged code.
 *
 *               _/  _/_/_/_/  _/      _/  _/_/_/  _/      _/
 *              _/  _/        _/_/    _/    _/    _/_/    _/
 *             _/  _/_/_/    _/  _/  _/    _/    _/  _/  _/
 *      _/    _/  _/        _/    _/_/    _/    _/    _/_/
 *       _/_/    _/_/_/_/  _/      _/  _/_/_/  _/      _/
 */

///////////////////////////////////////////////////////////////////////

#include <stdint.h>  //uint32_t
#include <unistd.h>  // unsigned int sleep(unsigned int seconds);
#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>  // std::istream_iterator
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef double lf;
typedef long double llf;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<long long> vl;

#define _USE_MATH_DEFINES

#define forr(i, a, b) for (__typeof(a) i = (a); i <= (b); i++)
#define rof(i, b, a) for (__typeof(a) i = (b); i >= (a); i--)
#define rep(i, n) for (__typeof(n) i = 0; i < (n); i++)
#define forit(i, s) \
  for (__typeof((s).end()) i = (s).begin(); i != (s).end(); ++i)
#define all(ar) ar.begin(), ar.end()
#define fill(a, val) memset((a), (val), sizeof((a)))
#define clr(a) memset((a), 0, sizeof((a)))
#define sz(a) (int)a.size()

#define pb push_back

#ifndef ONLINE_JUDGE
#define nl cerr << '\n'
#define sp cerr << ' '
#define ckk cerr << "###############\n"
#define debug1(x) cerr << #x << ": " << (x) << '\n'
#define debug2(x, y) \
  cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << '\n'
#define debug3(x, y, z)                                                        \
  cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << '\t' << #z << ": " \
       << (z) << '\n'
#else
#define nl
#define sp
#define ckk
#define debug1(x)
#define debug2(x, y)
#define debug3(x, y, z)
#endif

#define PI acos(-1.0)
#define INF 0x7fffffff
#define MOD 1000000007
#define EPS 1e-7
#define MAX 10000007  // 1e7+7

////////////////////////// START HERE //////////////////////////

class SegmentTree {
  static const int mx = 100001;
  int tree[mx * 3];

 public:
  int arr[mx];

  void init(int node, int b, int e) {
    if (b == e) {
      tree[node] = arr[b];
      return;
    }

    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = min(tree[Left], tree[Right]);  // sum -> use '+' instead of min
  }

  int query(int node, int b, int e, int i, int j) {
    if (i > e || j < b) return INT_MAX;  // out of range (for sum -> return 0)
    if (b >= i && e <= j) return tree[node];  // relevant segment
    int Left = node * 2;                      // break it down
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return min(p1, p2);  // sum -> use '+' instead of min
  }

  void update(int node, int b, int e, int i, int newvalue) {
    if (i > e || i < b) return;  // out of range
    if (b >= i && e <= i) {      // relevant segment
      tree[node] = newvalue;
      return;
    }

    int Left = node * 2;  // break it down
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = min(tree[Left], tree[Right]);  // sum -> use '+' instead of min
  }
};

int main() {
  int n, q, t, cs = 0;
  SegmentTree SegTree;
  cin >> t;
  while (t--) {
    cin >> n >> q;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &SegTree.arr[i]);
    }

    SegTree.init(1, 1, n);
      printf("Case %d:\n", ++cs);
    for (int i = 0, l, r; i < q; i++) {
      cin >> l >> r;
      printf("%d\n", SegTree.query(1, 1, n, l, r));
    }
  }
  return 0;
}
