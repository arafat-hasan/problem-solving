/*
 * FILE: Potentiometers-12086.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: https://onlinejudge.org/external/120/12086.pdf
 *
 * DATE CREATED: 27-03-20 23:51:56 (+06)
 * LAST MODIFIED: 28-03-20 01:31:59 (+06)
 *
 * VERDICT: Accepetd
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 27-03-20     1.0         Deleted code is debugged code.
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

struct FenwickTree {  // One based
  vector<int> bit;  // binary indexed tree
  int MaxIdx;

  FenwickTree(int n) {
    MaxIdx = n;
    bit.assign(n + 1, 0);
  }

  FenwickTree(vector<int> a) : FenwickTree((int)a.size()) {
    for (size_t i = 0; i < a.size(); i++) update((int)i + 1, a[i]);
  }

  int read(int idx) {
    int sum = 0;
    while (idx > 0) {
      sum += bit[idx];
      idx -= (idx & -idx);
    }
    return sum;
  }

  int read(int l, int r) { return read(r) - read(l - 1); }

  int readSingle(int idx) {
    int sum = bit[idx];  // this sum will be decreased
    if (idx > 0) {       // the special case
      int z = idx - (idx & -idx);
      idx--;  // idx is not important anymore, so instead y, you can use idx
      while (idx != z) {  // at some iteration idx (y) will become z
        sum -= bit[idx];
        // substruct tree frequency which is between y and "the same path"
        idx -= (idx & -idx);
      }
    }
    return sum;
  }

  void scale(int c) {
    for (int i = 1; i <= MaxIdx; i++) bit[i] = bit[i] / c;
  }

  void update(int idx, int val) {
    while (idx <= MaxIdx) {
      bit[idx] += val;
      idx += (idx & -idx);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, cs = 0;
  while (cin >> n and n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    FenwickTree BITree(v);
    string str;
    int l, r, idx, val;
    if (cs >= 1) cout << '\n';
    cout << "Case " << ++cs << ":\n";
    while (cin >> str) {
      if (str == "M") {
        cin >> l >> r;
        cout << BITree.read(l, r) << '\n';
      } else if (str == "S") {
        cin >> idx >> val;
        int tmp = val - BITree.readSingle(idx);
        BITree.update(idx, tmp);
      } else if (str == "END") {
        break;
      }
    }
  }
  return 0;
}
