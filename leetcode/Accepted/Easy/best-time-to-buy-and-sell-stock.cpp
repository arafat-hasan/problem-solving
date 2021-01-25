/*
 * FILE: best-time-to-buy-and-sell-stock.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * DATE CREATED: 25-01-21 23:42:47 (+06)
 * LAST MODIFIED: 26-01-21 00:06:12 (+06)
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

class SolutionAdhoc {
 public:
  int maxProfit(vector<int>& prices) {
    vector<pair<int, int>> v(prices.size(), make_pair(INT_MAX, INT_MIN));
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < (int)prices.size(); ++i) {
      if (prices[i] < mn) {
        mn = prices[i];
      }
      v[i].first = mn;
    }

    for (int i = (int)prices.size() - 1; i >= 0; --i) {
      if (prices[i] > mx) {
        mx = prices[i];
      }
      v[i].second = mx;
    }

    int ans = 0;
    for (int i = 0; i < (int)v.size(); ++i) {
      if (v[i].second - v[i].first > ans) ans = v[i].second - v[i].first;
    }
    return ans;
  }
};

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    int minPrice = INT_MAX;
    for (int i = 0; i < (int)prices.size(); i++) {
      minPrice = min(minPrice, prices[i]);
      maxProfit = max(maxProfit, prices[i] - minPrice);
    }
    return maxProfit;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  Solution obj;
  while (true) {
    vector<int> v;
    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> tmp;
      v.push_back(tmp);
    }
    cout << obj.maxProfit(v) << endl;
  }
  return 0;
}
