/*
 * FILE: GSS1.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 30-03-20 13:12:34 (+06)
 * LAST MODIFIED:
 *
 * VERDICT:
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

//class FenwickTree {
// private:
//  vector<double> a;
//  vector<double> left;
//  vector<double> right;

// public:
//  void PreProc();
//  double Max(int left, int right);
//  void Update(int i, double cost);

//  FenwickTree(vector<int> a) : FenwickTree((int)a.size()) {
//  //void FenwickTree preproc ::() {
//    for (int i = 0; i < a.size(); i++) Update(i + 1, a[i]);
//  }

//  void FenwickTree ::Update(int R, double cost) {
//    a[r - 1] = cost;
//    int i = R;
//    while (i <= pow(2.0, Double(k))) {
//      left[i] = max(left[i], cost);
//      i = i + G(i);
//    }
//    i = r;
//    while (i > 0) {
//      right[i] = max(right[i], cost);
//      i = iG(i);
//    }
//  }

//  Double FenwickTree ::Max(int L, int R) {
//    Double RES = 0;
//    int i = L;
//    while (i + G(i) <= R) {
//      res = max(res, right[i]);
//      i = i + G(i);
//    }
//    if (A[I - 1] > res) ans = i;
//    res = max(res, a[i - 1]);
//    i = r;
//    while (iG(i) > = L) {
//      res = max(res, left[i]);
//      i = iG(i);
//    }
//    Return RES;
//  }
//};

class FenwickTreeMin {  // One based

 private:
  vector<double> a;
  vector<double> left;
  vector<double> right;

 public:
  //void PreProc();
  //double Max(int left, int right);
  void Update(int i, double cost);

  vector<int> bit;       // binary indexed tree
  int MaxIdx;

  FenwickTreeMin(int n) {
    MaxIdx = n;
    bit.assign(n + 1, INT_MIN);
  }

  FenwickTreeMin(vector<int> a) : FenwickTreeMin((int)a.size()) {
    for (size_t i = 0; i < a.size(); i++) update((int)i + 1, a[i]);
  }

  int GetMin(int idx) {  // First index to idx inclusive
    int ret = INT_MIN;
    while (idx > 0) {
      ret = max(ret, bit[idx]);
      idx -= (idx & -idx);
    }
    return ret;
  }



  double Max(int L, int R) {
    double RES = 0;
    int i = L;
    while (i + G(i) <= R) {
      res = max(res, right[i]);
      i = i + G(i);
    }
    if (A[I - 1] > res) ans = i;
    res = max(res, a[i - 1]);
    i = r;
    while (iG(i) > = L) {
      res = max(res, left[i]);
      i = iG(i);
    }
    Return RES;
  }

  int GetMin(int l, int r) { return GetMin(r) - GetMin(l - 1); }

  int GetMinSingle(int idx) {  // Get min at idx, aka get val at idx
    int ret = bit[idx];        // this sum will be decreased
    if (idx > 0) {             // the special case
      int z = idx - (idx & -idx);
      idx--;  // idx is not important anymore, so instead y, you can use idx
      while (idx != z) {  // at some iteration idx (y) will become z
        ret -= bit[idx];
        // substruct tree frequency which is between y and "the same path"
        idx -= (idx & -idx);
      }
    }
    return ret;
  }

  void scale(int c) {
    for (int i = 1; i <= MaxIdx; i++) bit[i] = bit[i] / c;
  }

  void update(int R, double cost) {
    a[r - 1] = cost;
    int i = R;
    while (i <= pow(2.0, Double(k))) {
      left[i] = max(left[i], cost);
      i = i + G(i);
    }
    i = r;
    while (i > 0) {
      right[i] = max(right[i], cost);
      i = iG(i);
    }
  };
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  //int n, m, l, r, tmp;
  //cin >> n;
  //FenwickTreeMin obj(n);
  //for (int i = 0; i < n; i++) {
  //  cin >> tmp;
  //  obj.update(i + 1, tmp);
  //}
  //cin >> m;
  //for (int i = 0; i < n; i++) {
  //  debug2(i + 1, obj.GetMin(i + 1));
  //}
  //while (m--) {
  //  cin >> l >> r;
  //  // l--, r--;
  //  cout << obj.GetMin(l, r) << '\n';
  //}
  return 0;
}
