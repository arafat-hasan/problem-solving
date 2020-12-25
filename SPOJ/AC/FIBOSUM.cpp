/*
 * FILE: FIBOSUM.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: https://www.spoj.com/problems/FIBOSUM/en/
 *
 * DATE CREATED: 24-03-20 14:47:52 (+06)
 * LAST MODIFIED: 24-03-20 18:02:47 (+06)
 *
 * VERDICT: Accepetd
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 24-03-20     1.0         Deleted code is debugged code.
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

class fibo {
  // Firsr approach
  // function that returns nth Fibonacci number
  // Time Complexity: O(Logn)
  // Extra Space: O(Logn) if we consider the function call stack size, otherwise
  // O(1).
 public:
  ll fib(ll n) {
    ll F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0) return 0;
    power(F, n - 1);
    return F[0][0];
  }

 private:
  void power(ll F[2][2], ll n) {
    if (n == 0 || n == 1) return;
    ll M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0) multiply(F, M);
  }

  void multiply(ll F[2][2], ll M[2][2]) {
    ll x = (F[0][0] * M[0][0] + F[0][1] * M[1][0]) % MOD;
    ll y = (F[0][0] * M[0][1] + F[0][1] * M[1][1]) % MOD;
    ll z = (F[1][0] * M[0][0] + F[1][1] * M[1][0]) % MOD;
    ll w = (F[1][0] * M[0][1] + F[1][1] * M[1][1]) % MOD;

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
  }

  // Second approach
  // Below is one more interesting recurrence formula that can be used to find
  // n’th Fibonacci Number in O(Log n) time.
  // If n is even then k = n/2:
  // F(n) = [2*F(k-1) + F(k)]*F(k)
  // If n is odd then k = (n + 1)/2
  // F(n) = F(k)*F(k) + F(k-1)*F(k-1)
  // Time complexity of this solution is O(Log n) as we divide the problem to
  // half in every recursive call.

  // Create an array for memoization
  int f[1000] = {0};  // Change 1000 here

  // Returns n'th fuibonacci number using table f[]
 public:
  int fib2(int n) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1 || n == 2) return (f[n] = 1);

    // If fib(n) is already computed
    if (f[n]) return f[n];

    int k = (n & 1) ? (n + 1) / 2 : n / 2;

    // Applyting above formula [Note value n&1 is 1
    // if n is odd, else 0.
    f[n] = (n & 1) ? (fib2(k) * fib2(k) + fib2(k - 1) * fib2(k - 1))
                   : (2 * fib2(k - 1) + fib2(k)) * fib2(k);

    return f[n];
  }

  // Another approach:(Using formula)
  // Time Complexity: O(1)
  // Space Complexity: O(1)
  int fib3(int n) {
    double phi = (1 + sqrt(5)) / 2;
    return (int)round(pow(phi, n) / sqrt(5));
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll t, n, m;
  fibo fibo;
  cin >> t;
  while(t--){
    cin >> n >> m;
    ll ans = (fibo.fib(m+2) - fibo.fib(n+1)) % MOD;
    ans = ans < 0? ans + MOD : ans;
    cout << ans << '\n';
  }
  return 0;
}
