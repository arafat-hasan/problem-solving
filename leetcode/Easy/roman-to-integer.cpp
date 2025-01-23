/*
 * FILE: roman-to-integer.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK:
 * DATE CREATED: 23-07-21 16:45:03 (+06)
 * LAST MODIFIED: 23-07-21 17:03:54 (+06)
 * VERDICT: Accepetd
 * VERSION: 1.0
 * DESCRIPTION: Deleted code is debugged code.
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

////////////////////////// START HERE //////////////////////////

class Solution {
 public:
  int romanToInt(string s) {
    int sum = 0;

    for (size_t i = 0; i < s.size(); ++i) {
      if (s[i] == 'I' and s[i + 1] == 'V')
        sum += 4, ++i;
      else if (s[i] == 'I' and s[i + 1] == 'X')
        sum += 9, ++i;
      else if (s[i] == 'X' and s[i + 1] == 'L')
        sum += 40, ++i;
      else if (s[i] == 'X' and s[i + 1] == 'C')
        sum += 90, ++i;
      else if (s[i] == 'C' and s[i + 1] == 'D')
        sum += 400, ++i;
      else if (s[i] == 'C' and s[i + 1] == 'M')
        sum += 900, ++i;
      else if (s[i] == 'I')
        sum += 1;
      else if (s[i] == 'V')
        sum += 5;
      else if (s[i] == 'X')
        sum += 10;
      else if (s[i] == 'L')
        sum += 50;
      else if (s[i] == 'C')
        sum += 100;
      else if (s[i] == 'D')
        sum += 500;
      else if (s[i] == 'M')
        sum += 1000;
    }

    return sum;
  }
};

