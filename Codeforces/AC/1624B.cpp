/*
 * FILE: 1624B.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://codeforces.com/contest/1624/problem/B
 * DATE CREATED: 10-01-22 22:24:04 (+06)
 * LAST MODIFIED: 11-01-22 01:31:11 (+06)
 * VERDICT: Accepetd
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
  int t, a, b, c;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    if (
        (((b + (b - a)) % c == 0) && (b + (b - a)) > 0 && b >= a) ||  // 20 25 30 : a, b correct
        (((b - (a - b)) % c == 0) && (b - (a - b)) > 0 && a >= b) ||  // 30 25 20 : a, b correct
        (((b - (c - b)) % a == 0) && (b - (c - b)) > 0 && c >= b) ||  // 20 25 30 : b, c correct
        (((b + (b - c)) % a == 0) && (b + (b - c)) > 0 && b >= c) ||  // 30 25 20 : b, c correct
        ((((a + c) / 2) % b == 0) && ((a + c) / 2) > 0 && (a + c) % 2 != 1)      // 20 25 30 :  a, c correct
    ) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }


  }
  return 0;
}
