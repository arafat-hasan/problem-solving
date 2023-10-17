/*
 * FILE: {{untitled}}
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: {{long_date}}
 * LAST MODIFIED: __last_modified
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * {{short_date}}     1.0         {{File Created}}
 *
 *                 _/  _/_/_/_/  _/      _/  _/_/_/  _/      _/
 *                _/  _/        _/_/    _/    _/    _/_/    _/
 *               _/  _/_/_/    _/  _/  _/    _/    _/  _/  _/
 *        _/    _/  _/        _/    _/_/    _/    _/    _/_/
 *         _/_/    _/_/_/_/  _/      _/  _/_/_/  _/      _/
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
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef double lf;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;

#define _USE_MATH_DEFINES

#define FileIn(file) freopen("input.txt", "r", stdin)
#define FileOut(file) freopen("output.txt", "w", stdout)
#define _FastIO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)

#define forr(i, a, b) for (__typeof(a) i = a; i <= b; i++)
#define rof(i, b, a) for (__typeof(a) i = b; i >= a; i--)
#define rep(i, n) for (__typeof(n) i = 0; i < n; i++)
#define forit(i, s) \
  for (__typeof((s).end()) i = (s).begin(); i != (s).end(); ++i)
#define all(ar) ar.begin(), ar.end()
#define fill(a, val) memset((a), (val), sizeof((a)))
#define clr(a) memset((a), 0, sizeof((a)))
#define sz(a) (int)a.size()

#define sfll(a) scanf("%lld", &a)
#define pfll(a) printf("%lld", a)
#define sflf(a) scanf("%lf", &a)
#define pflf(a) printf("%lf", a)
#define sff(a) scanf("%f", &a)
#define pff(a) printf("%f", a)
#define sf(a) scanf("%d", &a)
#define pf(a) printf("%d", a)

#define pb push_back
#define gc getchar
#define eb emplace_back

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
#define sp
#define nl
#define ckk
#define debug1(x)
#define debug2(x, y)
#define debug3(x, y, z)
#endif

#define max(a, b) (a < b ? b : a)
#define min(a, b) (a > b ? b : a)
#define sq(a) (a * a)

//////////////// BIT SET //////////////

// 2^n
#define bit(n) (1 << (n))
// Check ith bit of integer n, 0 or 1
#define bitchk(n, i) ((n & (1 << (i))) ? 1 : 0)
// set ith bit ON of the integer n
#define bit_on(n, i) n = (n | (1 << (i)))
// set ith bit OFF of the intger n
#define bit_off(n, i) n = (n & ~(1 << (i)))
// Toggle ith bit of integer n, set 0 if 1, set 1 if 0
#define bit_toggle(n, i) n = (n ^ (1 << (i)))
// Set ith bit to x (x is bool, 1 or 0) of the integer n
#define bit_setx(n, x, i) n = (n ^ ((-(x) ^ n) & (1 << (i))))

/// int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Year
/// int dx[]= {1,0,-1,0};int dy[]= {0,1,0,-1}; //4 Direction
/// int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
/// int dx[]= {2,1,-1,-2,-2,-1,1,2};int dy[]= {1,2,2,1,-1,-2,-2,-1}; //Knight
/// Direction

#define PI acos(-1.0)
#define INF 0x7fffffff
#define MOD 1000000007
#define EPS 1e-7
#define MAXN 32001
#define MAXS 100000008  // 1e8+8
#define MAX 10000007    // 1e7+7

template <class T>
void debug(T t) {
  cout << t << endl;
}

template <typename T, typename... Args>
void debug(T t, Args... args) {
  cout << t << '\t';
  debug(args...);
}

////////////////////////////////////////////////////////////////
////////////////////////// START HERE //////////////////////////
////////////////////////////////////////////////////////////////

////////////////////////// BFS //////////////////////////

class BFS_DIJKSTRA {
  vector<int> adj[100];  // for BFS & bfs_vis
  int cost[100];         // for BFS & bfs_vis
  int visited[100];      // for bfs_vis

  int bfs(int s, int n) {
    int i, cn, v, sz;

    for (i = 0; i < n; i++) cost[i] = INT_MAX;

    queue<int> Q;
    Q.push(s);
    cost[s] = 0;

    while (!Q.empty()) {
      cn = Q.front();
      Q.pop();
      sz = (int)adj[cn].size();

      for (i = 0; i < sz; i++) {
        v = adj[cn][i];

        if (cost[cn] + 1 < cost[v]) {
          Q.push(v);
          cost[v] = cost[cn] + 1;
        }
      }
    }

    return 0;
  }

  void bfs_visited(int s, int n) {
    int u, v, i, m;

    for (i = 0; i < n; i++) {
      visited[i] = 0;
      cost[i] = -1;
    }

    queue<int> Q;
    Q.push(s);
    visited[s] = 1;
    cost[s] = 0;

    while (!Q.empty()) {
      u = Q.front();
      Q.pop();
      m = (int)adj[u].size();

      for (i = 0; i < m; i++) {
        if (visited[adj[u][i]] == 0) {
          v = adj[u][i];
          visited[v] = 1;
          Q.push(v);
          cost[v] = cost[u] + 1;
        }
      }
    }
  }
  ////////////////////////// BFS END //////////////////////////

  ////////////////////////// DIJKSTRA //////////////////////////

  // See /media/jenin/Softwares/Programming/UVa/Accepted/Sending_email-10986.cpp
  //
  // typedef pair<int, int> pii;
  // typedef vector <pii> vpii;
  // typedef vector <int> vi;
  // graph declaration
  // vector<vpii> graph (n, vpii());

  void dijkstra(int s, vi *dist, vector<vpii> *graph) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0, s));

    while (!pq.empty()) {
      pii front = pq.top();
      pq.pop();
      int d = front.first, u = front.second;

      if (d == dist->at(u)) {
        for (int j = 0; j < (int)graph->at(u).size(); j++) {
          pii v = graph->at(u)[j];  // all outgoing edges from u

          if (dist->at(u) + v.second < dist->at(v.first)) {
            dist->at(v.first) = dist->at(u) + v.second;  // relax operation
            pq.push(pii(dist->at(v.first), v.first));
          }
        }
      }
    }
  }

  ////////////////////////// DIJKSTRA END //////////////////////////
};

////////////////////////// UNION FIND //////////////////////////
class UNION_FIND {
  int parent[26];

  void Make_Set(int x) { parent[x] = x; }

  int Find(int x) {
    if (x != parent[x]) parent[x] = Find(parent[x]);

    return parent[x];
  }

  void Union(int &x, int &y) {
    int PX = Find(x), PY = Find(y);
    parent[PX] = PY;
  }
  // example
  // if (Find(x) != Find(y)){
  //     Union(x, y);
  // }
};
////////////////////////// UNION FIND END //////////////////////////

class Topsort {
  int indegree[MAX];
  vector<int> adj[MAX], tops;

  // if 0 returned, topsort is not possible, 1 otherwise
  // order has been kept in tops
  // adj[] inserted in this way, u to v then asj[u].pb(v)
  // top sort relation is not bidirectional
  // cycle checking not needed
  // Top sort is not possible in DAG - Directed Acyclic Graph, 0 returned
  bool topsort(int size) {
    int k, i, v;

    for (k = 1; k <= size; k++) {
      for (i = 1; i <= size; i++) {
        if (indegree[i] == 0) {
          tops.push_back(i);
          v = (int)adj[i].size();

          for (int j = 0; j < v; j++) {
            indegree[adj[i][j]]--;
          }

          indegree[i]--;
          break;
        }
      }

      if (i > size) return 0;
    }

    return 1;
  }
};

////////////////////////// SIEVE //////////////////////////
class Primes {
  bool isPrime[MAXS];  // for sieve
  int prime[MAXS];     // for sieve

 public:
  bool isprime(int num) {
    if (num == 2) return true;

    if (num < 2 or num % 2 == 0) return false;

    int i, root = (int)sqrt(num);

    for (i = 3; i <= root; i += 2)
      if (num % i == 0) return false;

    return true;
  }

  int sieve(int n) {
    int i, res, j;
    double root = sqrt(n);
    isPrime[0] = isPrime[1] = 1;

    for (i = 4; i < n; i += 2) isPrime[i] = 1;

    for (i = 3, j = 0; i <= root; i += 2) {
      if (!isPrime[i]) {
        for (j = i * i; j < n; j += 2 * i) isPrime[j] = 1;
      }
    }

    for (i = 0, res = 0; i < n; i++) {
      if (isPrime[i] == 0) {
        prime[res++] = i;
      }
    }

    return (res - 1);
  }

  // bitwise seive
  // int isPrime[MAXS/32]; //for sieve
  // int prime[MAXS]; //for sieve

  int bit_sieve(int n) {
    int i, res, j;
    double root = sqrt(n);
    bit_on(isPrime[0], 0);
    bit_on(isPrime[0], 1);

    for (i = 4; i < n; i += 2) bit_on(isPrime[i >> 5], i & 31);

    for (i = 3, j = 0; i <= root; i += 2) {
      if (bitchk(isPrime[i >> 5], i & 31) == 0) {
        for (j = i * i; j < n; j += 2 * i) bit_on(isPrime[j >> 5], j & 31);
      }
    }

    for (i = 0, res = 0; i < n; i++) {
      if (bitchk(isPrime[i >> 5], i & 31) == 0) {
        prime[res++] = i;
      }
    }

    return (res - 1);
  }

  // Segmented Sieve of Eratosthenes

  int segsieve[100000];

  /// Returns number of primes between segment [a,b]
  int segmentedSieve(int a, int b, int primesize) {
    if (a == 1) a++;

    int sqrtn = (int)sqrt(b);
    memset(segsieve, 0, sizeof segsieve);  /// Make all index of segsieve 0.

    // maxprime is used in bit sieve or normal seive code
    for (int i = 0; i < primesize && prime[i] <= sqrtn; i++) {
      int p = prime[i];
      int j = p * p;

      /// If j is smaller than a, then shift it inside of segment [a,b]
      if (j < a) j = ((a + p - 1) / p) * p;

      for (; j <= b; j += p) {
        segsieve[j - a] = 1;  /// mark them as not prime
      }
    }

    int res = 0;

    for (int i = a; i <= b; i++) {
      /// If it is not marked, then it is a prime
      if (segsieve[i - a] == 0) res++;
    }

    return res;
  }
};
////////////////////////// SIEVE END //////////////////////////

////////////////////////// PRIME FACTOR //////////////////////////
class Prime_fact {
  int fact[100][2];              // for prime factor
  int isPrime[MAX], prime[MAX];  // Primes class
  // 100 will be replaced with max number of factors

 public:
  int primefactor(long long n, int primesize) {
    // res is return value of seive
    int i, j;

    if (n == 0 || isPrime[n] == 0) return 0;

    for (i = 0, j = 0; i < primesize; i++) {
      if (n % prime[i] == 0) {
        fact[j][0] = prime[i];
        fact[j][1] = 0;

        while (n % prime[i] == 0) {
          n /= prime[i];
          fact[j][1]++;
        }

        j++;
      }
    }

    return j;
  }
};

////////////////////////// EULER'S TOTIENT FUNCTION ////////////////////////

class Totient {
 public:
  // phi[i] stores euler totient function for i
  // gcdsum[j] stores result for value j
  int phi[MAX];
  int gcdsum[MAX];

  /// Computes and prints totien of all numbers
  /// smaller than or equal to n.
  /// http://www.geeksforgeeks.org/
  /// eulers-totient-function-for-all-numbers-smaller-than-or-equal-to-n/
  void compute(int n) {
    // Create and initialize an array to store
    // phi or totient values
    // long long phi[n + 1];
    for (int i = 1; i <= n; i++) phi[i] = i;  // indicates not evaluated yet

    // and initializes for product
    // formula.

    // Compute other Phi values
    for (int p = 2; p <= n; p++) {
      // If phi[p] is not computed already,
      // then number p is prime
      if (phi[p] == p) {
        // Phi of a prime number p is
        // always equal to p-1.
        phi[p] = p - 1;

        // update phi values of all
        // multiples of p
        for (int i = 2 * p; i <= n; i += p) {
          // Add contribution of p to its
          // multiple i by multiplying with
          // (1 - 1/p)
          phi[i] = (phi[i] / p) * (p - 1);
        }
      }
    }
  }

  // Precomputes result for all numbers till MAX
  void sumOfGcdPairs(int n) {
    // Precompute all phi value
    compute(n);

    // gcdsum[0] = 0;
    for (int i = 1; i < n; ++i) {
      // Iterate throght all the divisors
      // of i.
      for (int j = 2; i * j < n; ++j) gcdsum[i * j] += i * phi[j];
    }

    // Add summation of previous calculated sum
    for (int i = 2; i < n; i++) gcdsum[i] += gcdsum[i - 1];
  }

  // http://www.geeksforgeeks.org/eulers-totient-function/
  int phi_single(int n) {
    int res = n;  // Initialize result as n

    // Consider all prime factors of n and subtract their
    // multiples from result
    for (int p = 2; p * p <= n; ++p) {
      // Check if p is a prime factor.
      if (n % p == 0) {
        // If yes, then update n and result
        while (n % p == 0) n /= p;

        res -= res / p;
      }
    }

    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1) res -= res / n;

    return res;
  }
};

////////////////////////// EULER'S TOTIENT FUNCTION ////////////////////////

////////////////////////////// MOBIOUS FUNCTION ////////////////////////////

class Mobious {
  int mu[MAX];

  void func(int n) {
    int fact[100][2];  // for prime factor, declared in Prime_fact class
    Primes primes;
    Prime_fact prime_fact;
    int num_of_unique_factors, fl;
    int primesz = primes.sieve(MAXS);

    for (int i = 1; i <= n; i++) {
      num_of_unique_factors = prime_fact.primefactor(i, primesz);
      fl = 2;

      for (int j = 0; j < num_of_unique_factors; j++) {
        if (fact[j][1] > 1) {
          fl = 0;
          break;
        }
      }

      if (fl == 0)
        mu[i] = 0;
      else {
        if (num_of_unique_factors & 1)
          mu[i] = -1;
        else
          mu[i] = 1;
      }
    }
  }
};

////////////////////////////// MOBIOUS FUNCTION ////////////////////////////

void swap(int *x, int *y) {
  // Code to swap 'x' and 'y'
  *x = *x * *y;  // x now becomes 15
  *y = *x / *y;  // y becomes 10
  *x = *x / *y;  // x becomes 5
}

class fibo {
  // Firsr approach
  // function that returns nth Fibonacci number
  // Time Complexity: O(Logn)
  // Extra Space: O(Logn) if we consider the function call stack size, otherwise
  // O(1).
 public:
  int fib(int n) {
    int F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0) return 0;
    power(F, n - 1);
    return F[0][0];
  }

 private:
  void power(int F[2][2], int n) {
    if (n == 0 || n == 1) return;
    int M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0) multiply(F, M);
  }

  void multiply(int F[2][2], int M[2][2]) {
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

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

int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

// http://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
int gcdExtended(int a, int b, int *x, int *y) {
  // Base Case
  if (a == 0) {
    *x = 0;
    *y = 1;
    return b;
  }

  int x1, y1;  // To store results of recursive call
  int gcd = gcdExtended(b % a, a, &x1, &y1);
  // Update x and y using results of recursive
  // call
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}

int lcm(int a, int b) { return (a * b) / gcd(a, b); }

int lcm2(int a, int b) {
  int temp = a;

  while (1) {
    if (temp % b == 0 && temp % a == 0) break;

    temp++;
  }

  return temp;
}

char *strrev(char *str) {  // Used by big_int_sum & big_int_mul
  char *p1, *p2;

  if (!str || !*str) return str;

  for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
    *p1 ^= *p2;
    *p2 ^= *p1;
    *p1 ^= *p2;
  }

  return str;
}

////////////////////////// BIG NUMBER //////////////////////////
class Big_num {
  int sum_s(int a, int b, int c) {  // Used by big_int_sum & big_int_mul
    if (a + b + c > 9) return (a + b + c) % 10;

    return a + b + c;
  }
  int sum_c(int a, int b, int c) {  // Used by big_int_sum & big_int_mul
    if (a + b + c > 9) return (a + b + c) / 10;

    return 0;
  }
  int mul_s(int a, int b, int c) {  // Used by big_int_mul
    if (a * b + c > 9) return (a * b + c) % 10;

    return a * b + c;
  }
  int mul_c(int a, int b, int c) {  // Used by big_int_mul
    if (a * b + c > 9) return (a * b + c) / 10;

    return 0;
  }

  void big_int_sum(char *a, char *b, char *c) {  // a + b = c
    int len_a, len_b, i, j, k, carry;
    len_a = (int)strlen(a);
    len_b = (int)strlen(b);
    carry = 0;
    k = 0, i = len_a - 1, j = len_b - 1;

    for (; i >= 0 && j >= 0; j--, i--, k++) {
      c[k] = (char)(sum_s(a[i] - 48, b[j] - 48, carry) + 48);
      carry = sum_c(a[i] - 48, b[j] - 48, carry);
    }

    if (i >= 0 && i != j)
      for (; i >= 0; i--, k++) {
        c[k] = (char)(sum_s(a[i] - 48, 0, carry) + 48);
        carry = sum_c(a[i] - 48, 0, carry);
      }
    else if (j >= 0 && i != j)
      for (; j >= 0; j--, k++) {
        c[k] = (char)(sum_s(0, b[j] - 48, carry) + 48);
        carry = sum_c(0, b[j] - 48, carry);
      }

    if (carry != 0) c[k++] = (char)(carry + 48);

    c[k] = '\0';
    strrev(c);
  }

  void big_int_mul(char *x, char *y, char *t) {
    int i, j, k, C, r, xi, yi, Cs, m;
    C = 0, Cs = 0;

    for (i = 0;; i++)
      if (x[i] == '\0') break;

    xi = i - 1;

    for (i = 0;; i++)
      if (y[i] == '\0') break;

    yi = i - 1;

    for (i = 0; i < 502; i++) t[i] = '0';

    for (j = 0; yi >= 0; yi--, j++) {
      for (i = 0, k = xi; k >= 0; k--, i++) {
        r = mul_s(x[k] - 48, y[yi] - 48, C);
        C = mul_c(x[k] - 48, y[yi] - 48, C);
        m = t[i + j];
        t[i + j] = (char)(sum_s(r, m - 48, Cs) + 48);
        Cs = sum_c(r, m - 48, Cs);
      }

      t[i + j] = (char)(C + Cs + 48);
      C = 0;
      Cs = 0;
    }

    for (k = i + j; k > 0; k--) {
      if (t[k] != 48) {
        t[k + 1] = 0;
        break;
      }
    }

    t[k + 1] = 0;
    strrev(t);
  }

  unsigned long long big_int_div(char *a, unsigned long long b, char *c) {
    int la;
    int i, k = 0, flag = 0;
    unsigned long long temp = 1, reminder;
    la = (int)strlen(a);

    for (i = 0; i <= la; i++) a[i] = (char)(a[i] - 48);

    temp = a[0];
    reminder = a[0];

    for (i = 1; i <= la; i++) {
      if (b <= temp) {
        c[k++] = (char)(temp / b);
        temp = temp % b;
        reminder = temp;
        temp = temp * 10 + a[i];
        flag = 1;

      } else {
        reminder = temp;
        temp = temp * 10 + a[i];

        if (flag == 1) c[k++] = 0;
      }
    }

    for (i = 0; i < k; i++) {
      c[i] = (char)(c[i] + '0');
    }

    c[i] = '\0';

    if (i == 0) {
      c[i] = '0';
      c[1] = '\0';
    }

    return reminder;
  }

  // Multiplies str1 and str2, and prints result.
  // Time Complexity : O(m*n), where m and n are length of two number that
  // need to be multiplied.
  // ONLY NON-NEGATIVE
  void bigInt_mult(string &num1, string &num2, string &ans) {
    int n1 = (int)num1.size();
    int n2 = (int)num2.size();

    if (n1 == 0 || n2 == 0) {
      ans = "0";
      return;
    }

    // will keep the result number in vector
    // in reverse order
    vector<int> result(n1 + n2, 0);
    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;

    // Go from right to left in num1
    for (int i = n1 - 1; i >= 0; i--) {
      int carry = 0;
      int n1_next = num1[i] - '0';
      // To shift position to left after every
      // multiplication of a digit in num2
      i_n2 = 0;

      // Go from right to left in num2
      for (int j = n2 - 1; j >= 0; j--) {
        // Take current digit of second number
        int n2_next = num2[j] - '0';
        // Multiply with current digit of first number
        // and add result to previously stored result
        // at current position.
        int sum = n1_next * n2_next + result[i_n1 + i_n2] + carry;
        // Carry for next iteration
        carry = sum / 10;
        // Store result
        result[i_n1 + i_n2] = sum % 10;
        i_n2++;
      }

      // store carry in next cell
      if (carry > 0) result[i_n1 + i_n2] += carry;

      // To shift position to left after every
      // multiplication of a digit in num1.
      i_n1++;
    }

    // ignore '0's from the right
    int i = (int)result.size() - 1;

    while (i >= 0 && result[i] == 0) i--;

    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1) {
      ans = "0";
      return;
    }

    // generate the result string
    ans.clear();

    while (i >= 0) ans += std::to_string(result[i--]);
  }

  // Function for finding sum of larger numbers
  // https://www.geeksforgeeks.org/sum-two-large-numbers/
  // Time Complexity : O(n1 + n2) where n1 and n2 are lengths of two input
  // strings representing numbers.
  // ONLY NON-NEGATIVE
  void bigInt_sum(string &str1, string &str2, string &ans) {
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length()) swap(str1, str2);

    // Take an empty string for storing result
    ans = "";
    // Calculate lenght of both string
    int n1 = (int)str1.length(), n2 = (int)str2.length();
    int diff = n2 - n1;
    // Initialy take carry zero
    int carry = 0;

    // Traverse from end of both strings
    for (int i = n1 - 1; i >= 0; i--) {
      // Do school mathematics, compute sum of
      // current digits and carry
      int sum = ((str1[i] - '0') + (str2[i + diff] - '0') + carry);
      ans.push_back((char)(sum % 10 + '0'));
      carry = sum / 10;
    }

    // Add remaining digits of str2[]
    for (int i = n2 - n1 - 1; i >= 0; i--) {
      int sum = ((str2[i] - '0') + carry);
      ans.push_back((char)(sum % 10 + '0'));
      carry = sum / 10;
    }

    // Add remaining carry
    if (carry) ans.push_back((char)(carry + '0'));

    // reverse resultant string
    reverse(ans.begin(), ans.end());
  }
};
////////////////////////// BIG NUMBER END //////////////////////////

bool isleapyear(long int year) {
  /*Is year divided by 4? After every 100 years a leap year is not
  counted and after every 400 years we count leap year*/
  if ((((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0))
    return true;
  else
    return false;
}

int bigMod(int base, int power, int mod) {
  if (power == 0)
    return 1 % mod;
  else if (power % 2 == 1) {
    long long p1 = base % mod;
    long long p2 = (bigMod(base, power - 1, mod)) % mod;
    return (p1 * p2) % mod;

  } else if (power % 2 == 0) {
    long long p1 = (bigMod(base, power / 2, mod)) % mod;
    return (p1 * p1) % mod;
  }

  return 0;
}

int binarysearch(int *array, int end, int key) {
  // array must be sorted, if key is found return 0 based index,
  // else -1;
  int start = 0, mid;
  end--;

  while (start <= end) {
    mid = (start + end) / 2;

    if (key == array[mid])
      return mid;
    else if (key < array[mid])
      end = mid - 1;
    else
      start = mid + 1;
  }

  return -1;
}

///////////////////////////// SORTING ////////////////////////////

class Sorting {
  void bubble_sort(int *list, int n) {
    int c, d, t;

    for (c = 0; c < (n - 1); c++) {
      for (d = 0; d < n - c - 1; d++) {
        if (list[d] > list[d + 1]) {
          /* Swapping */
          t = list[d];
          list[d] = list[d + 1];
          list[d + 1] = t;
        }
      }
    }
  }

  void insertion_sort(int *array, int n) {
    int t, d, c;

    for (c = 1; c <= n - 1; c++) {
      d = c;

      while (d > 0 && array[d] < array[d - 1]) {
        t = array[d];
        array[d] = array[d - 1];
        array[d - 1] = t;
        d--;
      }
    }
  }

  // Merge sort
  void merge(int *a, int low, int high, int mid) {  // used by merge_sort
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;

    while (i <= mid && j <= high) {
      if (a[i] < a[j]) {
        c[k] = a[i];
        k++;
        i++;

      } else {
        c[k] = a[j];
        k++;
        j++;
      }
    }

    while (i <= mid) {
      c[k] = a[i];
      k++;
      i++;
    }

    while (j <= high) {
      c[k] = a[j];
      k++;
      j++;
    }

    for (i = low; i < k; i++) a[i] = c[i];
  }

  void merge_sort(int *a, int low, int high) {  // low and high inclusive
    int mid;

    if (low < high) {
      mid = (low + high) / 2;
      merge_sort(a, low, mid);
      merge_sort(a, mid + 1, high);
      merge(a, low, high, mid);
    }

    return;
  }

  void quick_sort(int *array, int start, int end) {
    // start and end inclusive
    int low = start, high = start, i;

    if (start < end) {
      for (i = start; i < end; i++) {
        if (array[i] < array[end]) {
          swap(array[i], array[low]);
          low++;
          high++;

        } else
          high++;
      }

      swap(array[end], array[low]);
      quick_sort(array, start, low - 1);
      quick_sort(array, low + 1, high);

    } else
      return;
  }

  // Heap sort start
  // How to use
  // First call Build_MaxHeap(n), where n in size of array arr
  //      Build_MaxHeap(n);
  // then call HeapSort(n);
  //      HeapSort(n);

  int arr[100];
  void MakeHeap(int i, int n) {
    int j, temp;
    temp = arr[i];
    j = 2 * i;

    while (j <= n) {
      if (j < n && arr[j + 1] > arr[j]) {
        j++;
      }

      if (temp > arr[j])
        break;
      else if (temp <= arr[j]) {
        arr[j / 2] = arr[j];
        j = 2 * j;
      }
    }

    arr[j / 2] = temp;
  }

  void HeapSort(int n) {
    int i, temp;

    for (i = n; i >= 2; i--) {
      temp = arr[i];
      arr[i] = arr[1];
      arr[1] = temp;
      MakeHeap(1, i - 1);
    }
  }

  void Build_MaxHeap(int n) {
    int i;

    for (i = n / 2; i >= 1; i--) {
      MakeHeap(i, n);
    }
  }
  // Heap sort end
};
///////////////////////////// SORTING ////////////////////////////

//////////// MOST SIGNIFICANT DIGIT ////////////

// Return most significant digit
uint32_t powers_of_10[33] = {
    1000000000, 1000000000, 100000000, 100000000, 100000000, 10000000, 10000000,
    10000000,   1000000,    1000000,   1000000,   1000000,   100000,   100000,
    100000,     10000,      10000,     10000,     1000,      1000,     1000,
    1000,       100,        100,       100,       10,        10,       10,
    1,          1,          1,         1,         1};

int CalcFirstDecimalDigit(uint32_t x) {
  int leading_zeros = __builtin_clz(x);
  x /= powers_of_10[leading_zeros];

  if (x >= 10)
    return 1;
  else
    return x;
}

int most_significant_digit(int n) {
  double K = log10(n);
  K = K - floor(K);
  int X = (int)pow(10, K);
  return X;
}

//////////// MOST SIGNIFICANT DIGIT END ////////////

// https://www.geeksforgeeks.org/count-sum-of-digits-in-numbers-from-1-to-n/
// Function to computer sum of digits in numbers from 1 to n
// Comments use example of 328 to explain the code
int sumOfDigitsFrom1ToN(int n) {
  // base case: if n<10 return sum of
  // first n natural numbers
  if (n < 10) return n * (n + 1) / 2;

  // d = number of digits minus one in n. For 328, d is 2
  int d = (int)log10(n);
  // computing sum of digits from 1 to 10^d-1,
  // d=1 a[0]=0;
  // d=2 a[1]=sum of digit from 1 to 9 = 45
  // d=3 a[2]=sum of digit from 1 to 99 = a[1]*10 + 45*10^1 = 900
  // d=4 a[3]=sum of digit from 1 to 999 = a[2]*10 + 45*10^2 = 13500
  int *a = new int[d + 1];
  a[0] = 0, a[1] = 45;

  for (int i = 2; i <= d; i++)
    a[i] = (int)(a[i - 1] * 10 + 45 * ceil(pow(10, i - 1)));

  // computing 10^d
  int p = (int)ceil(pow(10, d));
  // Most significant digit (msd) of n,
  // For 328, msd is 3 which can be obtained using 328/100
  int msd = n / p;
  // EXPLANATION FOR FIRST and SECOND TERMS IN BELOW LINE OF CODE
  // First two terms compute sum of digits from 1 to 299
  // (sum of digits in range 1-99 stored in a[d]) +
  // (sum of digits in range 100-199, can be calculated as 1*100 + a[d]
  // (sum of digits in range 200-299, can be calculated as 2*100 + a[d]
  //  The above sum can be written as 3*a[d] + (1+2)*100
  // EXPLANATION FOR THIRD AND FOURTH TERMS IN BELOW LINE OF CODE
  // The last two terms compute sum of digits in number from 300 to 328
  // The third term adds 3*29 to sum as digit 3 occurs in all numbers
  //                from 300 to 328
  // The fourth term recursively calls for 28
  return msd * a[d] + (msd * (msd - 1) / 2) * p + msd * (1 + n % p) +
         sumOfDigitsFrom1ToN(n % p);
}

// www.geeksforgeeks.org/finding-sum-of-digits-of-a-number-until-sum-becomes-single-digit
// Finding sum of digits of a number until sum becomes single digit
int digSum(int n) {
  if (n == 0) return 0;

  return (n % 9 == 0) ? 9 : (n % 9);
}

template <class T>
int numDigits(T number) {
  int digits = 0;

  if (number < 0) digits = 1;

  while (number) {
    number /= 10;
    digits++;
  }

  return digits;
}

////////////////////////// SPARSE TABLE //////////////////////////

class Sparse_table {
  //#define Max 10000005
  int ST[24][MAX];
  int Array[MAX];

 public:
  Sparse_table(int N) {
    for (int i = 0; i < N; i++) ST[0][i] = i;

    for (int k = 1; (1 << k) < N; k++) {
      for (int i = 0; i + (1 << k) <= N; i++) {
        int x = ST[k - 1][i];
        int y = ST[k - 1][i + (1 << (k - 1))];
        ST[k][i] = Array[x] <= Array[y] ? x : y;
      }
    }
  }

  int RMQ(int i, int j) {
    // return min value index number of Array from i to j, including
    // if(i == j) return i;
    int k = (int)log2(j - i);
    int x = ST[k][i];
    int y = ST[k][j - (1 << k) + 1];
    return Array[x] <= Array[y] ? x : y;
  }
};
////////////////////////// SPARSE TABLE END //////////////////////////

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

struct FenwickTree {  // One based
  vector<int> bit;    // binary indexed tree
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

////////////////////////// INIX TO POSTFIX //////////////////////////

// deque: Every element of the equation is separate string in the deque

vector<string> infix_to_postfix(deque<string> v) {
  vector<string> P;
  stack<string> Stk;
  v.push_front("(");
  v.push_back(")");

  for (int i = 0; i < (int)v.size(); i++) {
    string tmp = v[i];

    /// Case 1 : number
    if (tmp[0] >= '0' && tmp[0] <= '9') {
      P.push_back(tmp);
    }

    /// Operator
    else if (tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/") {
      if (tmp == "+" || tmp == "-") {
        while (!Stk.empty() && (Stk.top() == "+" || Stk.top() == "-" ||
                                Stk.top() == "*" || Stk.top() == "/")) {
          P.push_back(Stk.top());
          Stk.pop();
        }

      } else if (tmp == "*" || tmp == "/") {
        while (!Stk.empty() && (Stk.top() == "*" || Stk.top() == "/")) {
          P.push_back(Stk.top());
          Stk.pop();
        }
      }

      Stk.push(tmp);

    } else {
      if (tmp == "(")
        Stk.push(tmp);
      else {
        while (Stk.top() != "(") {
          P.push_back(Stk.top());
          Stk.pop();
        }

        if (!Stk.empty()) Stk.pop();
      }
    }
  }

  return P;
}

////////////////////////// INIX TO POSTFIX //////////////////////////

////////////////////////// IS SUBSECUENCE //////////////////////////

class Subsecuence {
  // Returns true if str1[] is a subsequence of str2[]. m is
  // length of str1 and n is length of str2
  bool isSubSequence(char str1[], char str2[], int m, int n) {
    // Base Cases
    if (m == 0) return true;

    if (n == 0) return false;

    // If last characters of two strings are matching
    if (str1[m - 1] == str2[n - 1])
      return isSubSequence(str1, str2, m - 1, n - 1);

    // If last characters are not matching
    return isSubSequence(str1, str2, m, n - 1);
  }

  // Returns true if str1[] is a subsequence of str2[]. m is
  // length of str1 and n is length of str2
  bool isSubSequence_it(char str1[], char str2[], int m, int n) {
    int j = 0;  // For index of str1 (or subsequence

    // Traverse str2 and str1, and compare current character
    // of str2 with first unmatched char of str1, if matched
    // then move ahead in str1
    for (int i = 0; i < n && j < m; i++)
      if (str1[j] == str2[i]) j++;

    // If all characters of str1 were found in str2
    return (j == m);
  }

  ////////////////////////// IS SUBSECUENCE //////////////////////////

  ////////////////////////// LCS //////////////////////////

  int dp[1010][1010];
  /* Returns length of LCS for X[0..m-1], Y[0..n-1] */
  // last to first, m and n is size of strings
  int lcs(char *X, char *Y, int m, int n) {
    if (m == 0 || n == 0) return 0;

    if (dp[m][n] != -1) return dp[m][n];

    if (X[m - 1] == Y[n - 1])
      return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1);
    else
      return dp[m][n] = max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
  }

  // dp array needed, last to first
  string ans;  // store lcs here
  void lcs_print(string X, string Y, int m, int n) {
    if (m == -1 or n == -1) {
      reverse(all(ans));
      cout << ans << endl;
      return;
    }

    if (X[m - 1] == Y[n - 1]) {
      ans += X[m - 1];
      lcs_print(X, Y, m - 1, n - 1);

    } else {
      if (dp[m - 1][n] > dp[m][n - 1])
        lcs_print(X, Y, m - 1, n);
      else
        lcs_print(X, Y, m, n - 1);
    }
  }

  /* Returns length of LCS for X[0..m-1], Y[0..n-1] */
  int lcs_it(char *X, char *Y, int m, int n) {
    int i, j;

    // Following steps build L[m+1][n+1] in bottom up fashion. Note
    // that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1]
    for (i = 0; i <= m; i++) {
      for (j = 0; j <= n; j++) {
        if (i == 0 || j == 0)
          dp[i][j] = 0;
        else if (X[i - 1] == Y[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    /* dp[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
    return dp[m][n];
  }

  // LCS PRINT

  void lcs_print(char *X, char *Y, int m, int n) {
    // int dp[m + 1][n + 1]; // needed, declare before

    // Following steps build L[m+1][n+1] in bottom up fashion. Note
    // that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1]
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= n; j++) {
        if (i == 0 || j == 0)
          dp[i][j] = 0;
        else if (X[i - 1] == Y[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    // Following code is used to print LCS
    int index = dp[m][n];
    // Create a character array to store the lcs string
    char lcs[index + 1];
    lcs[index] = '\0';  // Set the terminating character
    // Start from the right-most-bottom-most corner and
    // one by one store characters in lcs[]
    int i = m, j = n;

    while (i > 0 && j > 0) {
      // If current character in X[] and Y are same, then
      // current character is part of LCS
      if (X[i - 1] == Y[j - 1]) {
        // Put current character in result
        lcs[index - 1] = X[i - 1];
        // reduce values of i, j and index
        i--;
        j--;
        index--;
      }

      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (dp[i - 1][j] > dp[i][j - 1])
        i--;
      else
        j--;
    }

    // Print the lcs
    cout << "LCS of " << X << " and " << Y << " is " << lcs;
  }

  ////////////////////////// LCS END //////////////////////////

  ////////////////////////// LPS //////////////////////////

  // int dp[1005][1005];
  // Returns the length of the longest palindromic subsequence in seq
  int lps(string seq, int i, int j) {
    // Base Case 1: If there is only 1 character
    if (i == j) return 1;

    // Base Case 2: If there are only 2 characters and both are same
    if (seq[i] == seq[j] && i + 1 == j) return 2;

    if (dp[i][j] != -1) return dp[i][j];

    // If the first and last characters match
    if (seq[i] == seq[j]) return dp[i][j] = lps(seq, i + 1, j - 1) + 2;

    // If the first and last characters do not match
    return dp[i][j] = max(lps(seq, i, j - 1), lps(seq, i + 1, j));
  }

  // Returns the length of the longest palindromic subsequence in seq
  int lps_it(string str) {
    short DP[1001][1001];
    memset(DP, 0, sizeof(DP));
    int len = (int)str.length(), i, j;

    for (i = 0; i < len; i++) {
      for (j = 0; j + i < len; j++) {
        if (str[j] == str[i + j]) {
          DP[j][j + i] = (short)(DP[j + 1][j + i - 1] + (i == 0 ? 1 : 2));

        } else {
          DP[j][j + i] = max(DP[j + 1][j + i], DP[j][j + i - 1]);
        }
      }
    }

    return DP[0][len - 1];
  }

  // Function return the total palindromic subsequence
  int countPS(string str) {
    int N = (int)str.length();
    // create a 2D array to store the count of palindromic
    // subsequence
    int cps[N + 1][N + 1];
    memset(cps, 0, sizeof(cps));

    // palindromic subsequence of length 1
    for (int i = 0; i < N; i++) cps[i][i] = 1;

    // check subsequence of length L is palindrome or not
    for (int L = 2; L <= N; L++) {
      for (int i = 0; i < N; i++) {
        int k = L + i - 1;

        if (str[i] == str[k])
          cps[i][k] = cps[i][k - 1] + cps[i + 1][k] + 1;
        else
          cps[i][k] = cps[i][k - 1] + cps[i + 1][k] - cps[i + 1][k - 1];
      }
    }

    // return total palindromic subsequence
    return cps[0][N - 1];
  }

  ////////////////////////// LPS END //////////////////////////

  ////////////////////////// LIS //////////////////////////

  int lengthOfLIS(vector<int> &nums) {
    vector<int> res;
    for (size_t i = 0; i < nums.size(); i++) {
      auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
      if (it == res.end())
        res.push_back(nums[i]);
      else
        *it = nums[i];
    }
    return res.size();
  }


  int lengthOfLIS2(vector<int>& nums) {
    vector<int> lis(nums.size(), 1);
    for (size_t i = 1; i < nums.size(); ++i) {
      for (size_t j = 0; j < i; ++j) {
        if (nums[j] < nums[i] and lis[i] < lis[j] + 1) {
          lis[i] = lis[j] + 1;
        }
      }
    }
    return *max_element(lis.begin(), lis.end());
  }
  //////////////////////////////////// LIS END /////////////////////////////////
};

////////////////////////// IS SUBSECUENCE //////////////////////////

//////////////////////////// KADANE'S ALGO IN 1D /////////////////////////////

// Implementation of Kadane's algorithm for 1D array. The function
// returns the maximum sum and stores starting and ending indexes of the
// maximum sum subarray at addresses pointed by start and finish pointers
// respectively.
int kadane(int *arr, int *start, int *finish, int n) {
  // initialize sum, maxSum and
  int sum = 0, maxSum = INT_MIN, i;
  // Just some initial value to check for all negative values case
  *finish = -1;
  // local variable
  int local_start = 0;

  for (i = 0; i < n; ++i) {
    sum += arr[i];

    if (sum < 0) {
      sum = 0;
      local_start = i + 1;

    } else if (sum > maxSum) {
      maxSum = sum;
      *start = local_start;
      *finish = i;
    }
  }

  // There is at-least one non-negative number
  if (*finish != -1) return maxSum;

  // Special Case: When all numbers in arr[] are negative
  maxSum = arr[0];
  *start = *finish = 0;

  // Find the maximum element in array
  for (i = 1; i < n; i++) {
    if (arr[i] > maxSum) {
      maxSum = arr[i];
      *start = *finish = i;
    }
  }

  return maxSum;
}

////////////////////////// KADANE'S ALGO IN 1D END //////////////////////////

//////////////////////////// KADANE'S ALGO IN 2D ////////////////////////////

// The main function that finds maximum sum rectangle in M[][]
// use Kadane's algo in 1D, descripted avobe
int MAT[101][101];
int findMaxSum2D(int *finalTop, int *finalLeft, int *finalBottom,
                 int *finalRight, int ROW, int COL) {
  // Variables to store the final output
  int maxSum = INT_MIN;
  int left, right, i;
  int temp[ROW], sum, start, finish;

  // Set the left column
  for (left = 0; left < COL; ++left) {
    // Initialize all elements of temp as 0
    memset(temp, 0, sizeof(temp));

    // Set the right column for the left column set by outer loop
    for (right = left; right < COL; ++right) {
      // Calculate sum between current left and right for every row 'i'
      for (i = 0; i < ROW; ++i) temp[i] += MAT[i][right];

      // Find the maximum sum subarray in temp[]. The kadane()
      // function also sets values of start and finish.  So 'sum' is
      // sum of rectangle between (start, left) and (finish, right)
      //  which is the maximum sum with boundary columns strictly as
      //  left and right.
      sum = kadane(temp, &start, &finish, ROW);

      // Compare sum with maximum sum so far. If sum is more, then
      // update maxSum and other output values
      if (sum > maxSum) {
        maxSum = sum;
        *finalLeft = left;
        *finalRight = right;
        *finalTop = start;
        *finalBottom = finish;
      }
    }
  }

  return maxSum;
}

////////////////////////// KADANE'S ALGO IN 2D END //////////////////////////

////////////////////////// INTEGER TO ROMAN NUMERAL //////////////////////////

/*
 * http://rosettacode.org/wiki/Roman_numerals/Encode#C.2B.2B
 *
 * Create a function taking a positive integer as its parameter and returning a
 * string containing the Roman numeral representation of that integer. Modern
 * Roman numerals are written by expressing each digit separately, starting
 * with the left most digit and skipping any digit with a value of zero.
 */

string to_roman(int value) {
  struct romandata_t {
    int value;
    char const *numeral;
  };
  static romandata_t const romandata[] = {
      {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
      {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
      {5, "V"},    {4, "IV"},   {1, "I"},   {0, NULL}};  // end marker
  string result;

  for (romandata_t const *current = romandata; current->value > 0; ++current) {
    while (value >= current->value) {
      result += current->numeral;
      value -= current->value;
    }
  }

  return result;
}

//////////////////////// INTEGER TO ROMAN NUMERAL END ////////////////////////

/////////////////////////////// SLIDING WINDOW ///////////////////////////////
// Returns maximum sum in a subarray of size k.
int maxSum(int arr[], int n, int k) {
  // k must be greater
  if (n < k) return -1;

  // Compute sum of first window of size k
  int max_sum = 0;

  for (int i = 0; i < k; i++) max_sum += arr[i];

  // Compute sums of remaining windows by
  // removing first element of previous
  // window and adding last element of
  // current window.
  int window_sum = max_sum;

  for (int i = k; i < n; i++) {
    window_sum += arr[i] - arr[i - k];
    max_sum = max(max_sum, window_sum);
  }

  return max_sum;
}
////////////////////////// SLIDING WINDOW END //////////////////////////

/////////////////// MAXIMUM OF ALL SUBARRAYS OF SIZE K ///////////////////
// A Dequeue (Double ended queue) based method for printing maixmum element of
// all subarrays of size k
vector<int> maxofallKsubarray(int arr[], int n, int k) {
  // Create a Double Ended Queue, Qi that will store indexes of array
  // elements.. The queue will store indexes of useful elements in every
  // window and it will maintain decreasing order of values from front to
  // rear in Qi, i.e., arr[Qi.front[]] to arr[Qi.rear()] are sorted in
  // decreasing order
  vector<int> v;
  std::deque<int> Qi(k);
  /* Process first k (or first window) elements of array */
  int i;

  for (i = 0; i < k; ++i) {
    // For very element, the previous smaller elements are useless so
    // remove them from Qi
    while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
      Qi.pop_back();  // Remove from rear

    // Add new element at rear of queue
    Qi.push_back(i);
  }

  // Process rest of the elements, i.e., from arr[k] to arr[n-1]
  for (; i < n; ++i) {
    // The element at the front of the queue is the largest element of
    // previous window, so print it
    v.push_back(arr[Qi.front()]);

    // Remove the elements which are out of this window
    while ((!Qi.empty()) && Qi.front() <= i - k)
      Qi.pop_front();  // Remove from front of queue

    // Remove all elements smaller than the currently
    // being added element (remove useless elements)
    while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) Qi.pop_back();

    // Add current element at the rear of Qi
    Qi.push_back(i);
  }

  // Print the maximum element of last window
  v.push_back(arr[Qi.front()]);
  return v;
}

/////////////////// MAXIMUM OF ALL SUBARRAYS OF SIZE K ///////////////////

/////////////////// MINIMUM OF ALL SUBARRAYS OF SIZE K ///////////////////
// A Dequeue (Double ended queue) based method for printing maixmum element of
// all subarrays of size k
vector<int> minofallKsubarray(int arr[], int n, int k) {
  // Create a Double Ended Queue, Qi that will store indexes of array
  // elements The queue will store indexes of useful elements in every window
  // and it will maintain decreasing order of values from front to rear in
  // Qi, i.e., arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing
  // order
  vector<int> v;
  std::deque<int> Qi(k);
  /* Process first k (or first window) elements of array */
  int i;

  for (i = 0; i < k; ++i) {
    // For very element, the previous smaller elements are useless so
    // remove them from Qi
    while ((!Qi.empty()) && arr[i] <= arr[Qi.back()])
      Qi.pop_back();  // Remove from rear

    // Add new element at rear of queue
    Qi.push_back(i);
  }

  // Process rest of the elements, i.e., from arr[k] to arr[n-1]
  for (; i < n; ++i) {
    // The element at the front of the queue is the largest element of
    // previous window, so print it
    v.push_back(arr[Qi.front()]);

    // Remove the elements which are out of this window
    while ((!Qi.empty()) && Qi.front() <= i - k)
      Qi.pop_front();  // Remove from front of queue

    // Remove all elements smaller than the currently
    // being added element (remove useless elements)
    while ((!Qi.empty()) && arr[i] <= arr[Qi.back()]) Qi.pop_back();

    // Add current element at the rear of Qi
    Qi.push_back(i);
  }

  // Print the maximum element of last window
  v.push_back(arr[Qi.front()]);
  return v;
}
/////////////////// MINIMUM OF ALL SUBARRAYS OF SIZE K ///////////////////

//////////////////////////////// FACTORIAL ///////////////////////////////
long long factorial(int n) {
  if (n == 0)
    return 1;
  else
    return (n * factorial(n - 1));
}

// // C++ program to find last non-zero digit in n!
// http://www.geeksforgeeks.org/last-non-zero-digit-factorial/
// Initialize values of last non-zero digit of
// numbers from 0 to 9
int dig[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};

int lastNon0Digit(int n) {
  if (n < 10) return dig[n];

  // Check whether tens (or second last) digit
  // is odd or even
  // If n = 375, So n/10 = 37 and (n/10)%10 = 7
  // Applying formula for even and odd cases.
  if (((n / 10) % 10) % 2 == 0)
    return (6 * lastNon0Digit(n / 5) * dig[n % 10]) % 10;
  else
    return (4 * lastNon0Digit(n / 5) * dig[n % 10]) % 10;
}

// Function to return trailing 0s in factorial of n
// http://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/
int findTrailingZeros(int n) {
  // Initialize result
  int count = 0;

  // Keep dividing n by powers of 5 and update count
  for (int i = 5; n / i >= 1; i *= 5) count += n / i;

  return count;
}

//////////////////////////////// FACTORIAL ///////////////////////////////

//////////////////////////////// PARSING //////////////////////////////

// for single character delimiter
vector<string> split(const string &s, char delim) {
  vector<string> result;
  stringstream ss(s);
  string item;

  while (getline(ss, item, delim)) {
    result.push_back(item);
  }

  return result;
}

// for string delimiter
vector<string> split(string s, string delimiter) {
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  string token;
  vector<string> res;

  while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back(token);
  }

  res.push_back(s.substr(pos_start));
  return res;
}

//////////////////////////////// PARSING //////////////////////////////

/////////////////////////// STRING MATHCING ///////////////////////////
// http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char *pat, int M, int *lps) {
  // length of the previous longest prefix suffix
  int len = 0;
  lps[0] = 0;  // lps[0] is always 0
  // the loop calculates lps[i] for i = 1 to M-1
  int i = 1;

  while (i < M) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;

    } else {  // (pat[i] != pat[len])
      // This is tricky. Consider the example.
      // AAACAAAA and i = 7. The idea is similar
      // to search step.
      if (len != 0) {
        len = lps[len - 1];
        // Also, note that we do not increment
        // i here

      } else {  // if (len == 0)
        lps[i] = 0;
        i++;
      }
    }
  }
}

// Prints occurrences of txt[] in pat[]
void KMPSearch(char *pat, char *txt) {
  int M = (int)strlen(pat);
  int N = (int)strlen(txt);
  // create lps[] that will hold the longest prefix suffix
  // values for pattern
  int lps[M];
  // Preprocess the pattern (calculate lps[] array)
  computeLPSArray(pat, M, lps);
  int i = 0;  // index for txt[]
  int j = 0;  // index for pat[]

  while (i < N) {
    if (pat[j] == txt[i]) {
      j++;
      i++;
    }

    if (j == M) {
      printf("Found pattern at index %d \n", i - j);
      j = lps[j - 1];
    }

    // mismatch after j matches
    else if (i < N && pat[j] != txt[i]) {
      // Do not match lps[0..lps[j-1]] characters,
      // they will match anyway
      if (j != 0)
        j = lps[j - 1];
      else
        i = i + 1;
    }
  }
}

/////////////////////////// STRING MATHCING ///////////////////////////

/////////////////////////// N QUEEN ///////////////////////////

class N_Queen {
  int mat[1000][1000];
  int n_queen_board_size = 0;
  bool is_poss;

  bool isSafe(int row, int col) {
    int i, j;

    for (i = 0; i < col; i++)
      if (mat[row][i]) return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
      if (mat[i][j]) return false;

    for (i = row, j = col; j >= 0 && i < n_queen_board_size; i++, j--)
      if (mat[i][j]) return false;

    return true;
  }

  bool n_queen(int col) {
    if (col >= n_queen_board_size) return true;

    for (int i = 0; i < n_queen_board_size; i++) {
      if (isSafe(i, col)) {
        mat[i][col] = 1;

        if (n_queen(col + 1)) return true;

        mat[i][col] = 0;  // BACKTRACK
      }
    }

    return false;
  }

 public:
  N_Queen();
  N_Queen(int n) {
    n_queen_board_size = n;
    memset(mat, 0, sizeof(mat));
    is_poss = n_queen(0);
  }

  bool solve(int n) {
    n_queen_board_size = n;
    memset(mat, 0, sizeof(mat));
    is_poss = n_queen(0);
    return is_poss;
  }

  bool print(void) {
    if (!has_sol()) {
      cout << "No solution found\n";
      return false;
    }

    for (int i = 0; i < n_queen_board_size; i++) {
      for (int j = 0; j < n_queen_board_size; j++) {
        cout << mat[i][j] << ' ';
      }

      cout << endl;
    }

    return true;
  }
  bool has_sol(void) { return is_poss; }
};

///////////////////////////////// N QUEEN ////////////////////////////////////

///////////////////////////// TRAVELLING SALESMAN ///////////////////////////
class TSP {
 public:
  int dist[15][15];
  int dp[(1 << 12) + 5][12];

  int tsp(int n) {
    int p, ans;
    // Run Floyd–Warshall to remove Triangle-Inequality
    // It is not necessary for TSP
    // for (k = 0; k < n; k++) {
    //    for (i = 0; i < n; i++) {
    //        for (j = 0; j < n; j++) {
    //            if (i != j && i != k && j != k)
    //                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
    //        }
    //    }
    //}
    memset(dp, -1, sizeof(dp));
    dp[1][0] = 0;

    for (int i = 1; i < (1 << n); i++) {
      for (int j = 0; j < n; j++) {
        if (dp[i][j] == -1) continue;

        for (int k = 1; k < n; k++) {
          if ((i & (1 << k)) != 0)
            continue;  // check either kth bit of i is 0 : 1

          p = (i | (1 << k));  // ON kth bit of i and store it p

          if (dp[p][k] == -1) dp[p][k] = dp[i][j] + dist[j][k];

          dp[p][k] = min(dp[p][k], dp[i][j] + dist[j][k]);
        }
      }
    }

    ans = INF;

    for (int i = 1; i < n; i++) {
      if (dp[(1 << n) - 1][i] > 0)
        ans = min(ans, dp[(1 << n) - 1][i] + dist[i][0]);
    }

    return ans;
  }
};
///////////////////////////// TRAVELLING SALESMAN ///////////////////////////

////////////////////////// CONVEX HULL GRAHAM SCAN /////////////////////////
struct Point {
  int x, y;
};

vector<Point> points;

void get_points(int x, int y) { points.push_back({x, y}); }

Point p0;

Point nextToTop(stack<Point> &S) {
  Point p = S.top();
  S.pop();
  Point res = S.top();
  S.push(p);
  return res;
}

int distSq(Point p1, Point p2) {
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int orientation(Point p, Point q, Point r) {
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

  if (val == 0) return 0;

  return (val > 0) ? 1 : 2;
}

int compare(const void *vp1, const void *vp2) {
  Point *p1 = (Point *)vp1;
  Point *p2 = (Point *)vp2;
  int o = orientation(p0, *p1, *p2);

  if (o == 0) return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

  return (o == 2) ? -1 : 1;
}

void convexHull() {
  int n = (int)points.size();
  int ymin = points[0].y, min = 0;

  for (int i = 1; i < n; i++) {
    int y = points[i].y;

    if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
      ymin = points[i].y, min = i;
  }

  swap(points[0], points[min]);
  p0 = points[0];
  qsort(&points[1], n - 1, sizeof(Point), compare);
  int m = 1;

  for (int i = 1; i < n; i++) {
    while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0) i++;

    points[m] = points[i];
    m++;
  }

  if (m < 3) return;

  stack<Point> S;
  S.push(points[0]);
  S.push(points[1]);
  S.push(points[2]);

  for (int i = 3; i < m; i++) {
    while (orientation(nextToTop(S), S.top(), points[i]) != 2) S.pop();

    S.push(points[i]);
  }

  while (!S.empty()) {
    Point p = S.top();
    cout << "(" << p.x << ", " << p.y << ")" << endl;
    S.pop();
  }
}

////////////////////////// CONVEX HULL GRAHAM SCAN /////////////////////////

/////////////////////////////// MAGIC SQUARE //////////////////////////////

class Magic_Square {
 public:
  int mat[1000][1000];

  void print(int n) {
    int rowsum, corner = 0;
    vi v(n);
    rep(i, n) corner += mat[i][i];
    cout << "\nCalculated magic number is: " << (n * n * n + n) / 2 << endl;
    cout << "Magic square of order " << n << ":\n\n";
    rep(i, n) {
      rowsum = 0;
      rep(j, n) {
        cout << mat[i][j] << '\t';
        rowsum += mat[i][j];
        v[i] += mat[i][j];
      }
      cout << "|" << rowsum << endl;
    }
    rep(i, n) cout << "________";
    cout << "|_____" << endl;
    rep(i, n) cout << v[i] << '\t';
    cout << "|" << corner;
    cout << endl << endl;
  }

  void magic_single(int n) {
    cout << "I have found no pattern for order " << n << " :-(\n";
  }

  void magic_double(int n) {
    int mn = n / 4;

    for (int i = 0, revY = n - 1; i < n; i++, revY--) {
      for (int j = 0, revX = n - 1; j < n; j++, revX--) {
        if (j < mn or j >= (n - mn)) {
          if (i < mn or i >= (n - mn))
            mat[i][j] = (i * n) + (j + 1);
          else
            mat[i][j] = (revY * n) + (revX + 1);

        } else {
          if (i >= mn and i < (n - mn))
            mat[i][j] = (i * n) + (j + 1);
          else
            mat[i][j] = (revY * n) + (revX + 1);
        }

        // debug3(i, j, mat[i][j]);
      }
    }
  }

  void magic_odd(int n) {
    int blocks = (n * n), preX = n / 2, preY = 0;

    for (int i = 1, x = n / 2, y = 0; i <= blocks; i++, x++, y--) {
      if (x == n and y == -1)
        x--, y += 2;
      else if (x == n)
        x = 0;
      else if (y == -1)
        y = n - 1;

      if (mat[y][x]) x = preX, y = preY + 1;

      mat[y][x] = i;
      preX = x, preY = y;
      // debug3(x, y, mat[y][x]);
    }
  }
};
/////////////////////////////// MAGIC SQUARE //////////////////////////////

/////////////////////////////// PALINDROMES //////////////////////////////

class Palindrome {
 public:
  int isPalindrome(int n) {
    // Find reverse of n
    int rev = 0;

    for (int i = n; i > 0; i /= 10) rev = rev * 10 + i % 10;

    // If n and rev are same, then n is palindrome
    return (n == rev);
  }

  // A utility for creating palindrome
  int createPalindrome(int input, int b, bool isOdd) {
    int n = input;
    int palin = input;

    // checks if number of digits is odd or even
    // if odd then neglect the last digit of input in
    // finding reverse as in case of odd number of
    // digits middle element occur once
    if (isOdd) n /= b;

    // Creates palindrome by just appending reverse
    // of number to itself
    while (n > 0) {
      palin = palin * b + (n % b);
      n /= b;
    }

    return palin;
  }

  // Fruition to print decimal palindromic number
  void generatePaldindromes(int n) {
    int number;

    // Run two times for odd and even length palindromes
    for (int j = 0; j < 2; j++) {
      // Creates palindrome numbers with first half as i.
      // Value of j decided whether we need an odd length
      // of even length palindrome.
      int i = 1;

      while ((number = createPalindrome(i, 10, j % 2)) < n) {
        cout << number << " ";
        i++;
      }
    }
  }
};
/////////////////////////////// PALINDROMES //////////////////////////////

// Find if string ends with another string
// https://stackoverflow.com/a/874160/7829174
bool hasEnding(std::string const &fullString, std::string const &ending) {
  if (fullString.length() >= ending.length()) {
    return (0 == fullString.compare(fullString.length() - ending.length(),
                                    ending.length(), ending));

  } else {
    return false;
  }
}
// std::string ending = "nary";
// std::string test1 = "binary";
// std::cout << hasEnding (test1, ending) << std::endl;
// This will return 1, as binary ends with nary;

int main() {
  _FastIO;
  cout << "Hello World!\n";
  return 0;
}

///////////////////////////////////////////////////////////////////////////////

/*********************************************************************
__________________________BUILT_IN FUNCTIONS__________________________


----------------------------------------------------------------------
int sprintf(char *restrict buffer, const char *restrictformat, ...);
This function convert number to string with specified format.
Example:
int aInt = 368;
char str[15];
sprintf(str, "%d", aInt);
cout << str << endl;

int sscanf(const char *str, const char *format, ...)
sscanf (sentence,"%s %*s %d",str,&i);
On success, the function returns the number of items in the argument
list successfully filled. This count can match the expected number of
items or be less (even zero) in the case of a matching failure.
In the case of an input failure before any data could be successfully
interpreted, EOF is returned.
Defined in header <stdio.h>


----------------------------------------------------------------------
std::cin.getline();
getline can be provided a third argument--a "stop" character. This
character ends getline's input. The character is eaten and the
string is terminated. Example: std::cin.getline(str, 100, '|')
If std::cin.getline() is not provided a "stop" character as a third
argument, it will stop when it reaches a newline.
Example: std::cin.getline(str, 100)


----------------------------------------------------------------------
std::cin.ignore()
can be called three different ways:
1. No arguments: A single character is taken from the input buffer
and discarded:
std::cin.ignore(); //discard 1 character
2. One argument: The number of characters specified are taken from
the input buffer and discarded:
std::cin.ignore(33); //discard 33 characters
3. Two arguments: discard the number of characters specified, or
discard characters up to and including the specified delimiter
(whichever comes first):
std::cin.ignore(26, '\n');
//ignore 26 characters or to a newline, whichever comes first



----------------------------------------------------------------------
Formated I/O
Example: std::cout << std::right << setw(5) << 123 << endl;
//output:"  123"
std::cout.fill('X');
std::cout << setw(2) << one << std::endl;
//output: "X4"
#include <iomanip>

----------------------------------------------------------------------
Input and output in C++ is type safe and easy for common formats
using cin and cout. The following program listing shows some common
uses:

#include <iomanip.h>
#include <iostream.h>

int main()
{
    int n;
    float f;
    double d;
    char s[100];

    // input an integer
    cin >> n;
    // print an integer, no formatting
    cout << n << endl;
    // print an integer, padded on left with spaces to total 6 chars
    cout << setw(6) << n << endl;
    // print an integer, padded on right with spaces to total 6 chars
    cout << setw(-6) << n << endl;

    // input a string (whitespace delineated)
    cin >> s;
    // print a string, no formatting
    cout << s << endl;
    // print a string, padded with spaces on left to 20 chars
    cout << setw(20) << s << endl;
    // print a string, padded with spaces on right to 20 chars
    cout << setiosflags(ios::left) << setw(20) << s << endl;

    // input a single precision floating point number
    cin >> f;
    // print a float, default precision is 6 places
    cout << setiosflags(ios::fixed) << f << endl;
    // input a double precision floating point number
    cin >> d;
    // print a double, default precision is 6 places
    cout << d << endl;
    // print a double, 2 places of precision
    cout << setprecision(2) << d << endl;
    // print a double, 2 places of precision, padded with space to 10
    cout << setw(10) << setprecision(2) << d << endl;
}

Rember that you can combine C routine sprintf and C++ cout. For
example, if sprintf can give the desired formatting, use it to create
the desired string, then output using C++ I/O. It is probably not a
good idea to mix C and C++ input and output routines since they are
buffered routines and may produce undesirable re-ordering of
input/output.


----------------------------------------------------------------------
strcpy(char* des, char* src) //Copies src into des.


----------------------------------------------------------------------
double a = 18.12385;
cout << fixed << setprecision(3);
cout << a << endl;
//output: 18.124
#include <iomanip>
std::fixed, std::setprecision()


----------------------------------------------------------------------
next_permutation(str, str+strlen(str));
return non-zero if next permutation found, otherwise 0
    char str[] = "arafat";
    if(next_permutation(str, str+strlen(str)))
        cout << str << endl;
//output: arafta
#include <algorithm>



Define _USE_MATH_DEFINES before including math.h to expose these macro
definitions for common math constants.  These are placed under an #ifdef
since these commonly-defined names are not part of the C/C++ standards.


Definitions of useful mathematical constants
M_E        - e
M_LOG2E    - log2(e)
M_LOG10E   - log10(e)
M_LN2      - ln(2)
M_LN10     - ln(10)
M_PI       - pi
M_PI_2     - pi/2
M_PI_4     - pi/4
M_1_PI     - 1/pi
M_2_PI     - 2/pi
M_2_SQRTPI - 2/sqrt(pi)
M_SQRT2    - sqrt(2)
M_SQRT1_2  - 1/sqrt(2)


#define M_E        2.71828182845904523536
#define M_LOG2E    1.44269504088896340736
#define M_LOG10E   0.434294481903251827651
#define M_LN2      0.693147180559945309417
#define M_LN10     2.30258509299404568402
#define M_PI       3.14159265358979323846
#define M_PI_2     1.57079632679489661923
#define M_PI_4     0.785398163397448309616
#define M_1_PI     0.318309886183790671538
#define M_2_PI     0.636619772367581343076
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2    1.41421356237309504880
#define M_SQRT1_2  0.707106781186547524401

 ********************************************************************/
