/*
 * Problem: D. Dima and Lisa
 * Url: https://codeforces.com/problemset/problem/584/D
 * Judge: Codeforces
 * Contest: Codeforces Round 324 (Div. 2)
 * Date Created: Mon 03 Feb 2025 14:16:12 +06
 * Memory Limit: 256
 * Time Limit: 1000
 * Verdict: undefined
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

bool isPrime(int num) {
  if (num == 2) return true;

  if (num < 2 or num % 2 == 0) return false;

  int i, root = (int)sqrt(num);

  for (i = 3; i <= root; i += 2)
    if (num % i == 0) return false;

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;

  if (n == 3) {
    cout << "1\n3\n";
    return 0;
  }

  for (int i = n - 1; i > 0; i--) {
    if (isPrime(i)) {
      int rest = n - i;
      for (int j = 2; j <= rest; j++) {
        if (isPrime(j) and rest - j == 0) {
          cout << 2 << endl;
          cout << i << ' ' << j << endl;
          return 0;
        } else if (isPrime(j) and isPrime(rest - j)) {
          cout << 3 << endl;
          cout << i << ' ' << j << ' ' << rest - j << endl;
          return 0;
        }
      }
    }
  }

  return 0;
}
