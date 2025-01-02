/*
 * Problem: A. Petya and Strings
 * Url: https://codeforces.com/problemset/problem/112/A
 * Judge: Codeforces
 * Contest: Codeforces Beta Round 85 (Div. 2 Only)
 * Date Created: Thu 02 Jan 2025 13:50:28 +06
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

int main2() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string str1, str2;
  cin >> str1 >> str2;
  transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
  transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
  cerr << str1 << ' ' << str2 << endl;
  int res = !(str1 == str2);
  if (res == 1) {
    res = str1 > str2 ? 1 : -1;
  }
  cout << res << endl;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string str1, str2;
  cin >> str1 >> str2;
  bool flag = false;
  for (int i = 0; i < (int)str1.size(); i++) {
    if (tolower(str1[i]) > tolower(str2[i])) {
      flag = true;
      cout << 1 << endl;
      break;
    } else if (tolower(str1[i]) < tolower(str2[i])) {
      flag = true;
      cout << -1 << endl;
      break;
    }
  }
  if (!flag) cout << 0 << endl;
  return 0;
}
