/*
 * Problem: D. Manhattan Circle
 * Url: https://codeforces.com/contest/1985/problem/D
 * Judge: Codeforces
 * Contest: Codeforces Round 952 (Div. 4)
 * Date Created: Fri 10 Jan 2025 13:55:48 +06
 * Memory Limit: 256
 * Time Limit: 2000
 * Verdict: Accepted
 */

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    int mxRowMid = -1;
    int firstCol = -1, size = 0;

    for (int i = 0; i < n; i++) {
      int left = -1, right = -1;
      for (int j = 0; j < m; j++) {
        char tmp;
        cin >> tmp;
        if (tmp == '#') {
          if (firstCol == -1) firstCol = i;
          if (left == -1) left = j;
          right = j;
        }
      }
      int mid = (right + left) / 2;
      mxRowMid = max(mid, mxRowMid);
      size = max(size, right - left + 1);
    }
    int res_col = firstCol + size / 2 + 1;
    int res_row = mxRowMid + 1;
    cout << res_col << ' ' << res_row << endl;
  }

  return 0;
}
