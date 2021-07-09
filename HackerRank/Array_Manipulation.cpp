/*
 * FILE: Array_Manipulation.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://www.hackerrank.com/challenges/crush/problem
 * DATE CREATED: 02-07-21 00:51:14 (+06)
 * LAST MODIFIED: 03-07-21 17:27:59 (+06)
 * VERDICT:
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

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

long arrayManipulation(vector<vector<int>> queries) {
  int left = 0, right = 0;
  long long maxVal = INT_MIN;
  sort(queries.begin(), queries.end(),
       [](const vector<int> &a, const vector<int> &b) {
         return a[0] < b[0] or (a[0] <= b[0] and a[1] < b[1]);
       });

  for (auto query : queries) {
    int runLeft = query[0];
    int runRight = query[1];
    int k = query[2];
     debug3(runLeft, runRight, k);

    if (runLeft < left and runRight < left) {
      if (k > maxVal) {
        maxVal = k;
        left = runLeft;
        right = runRight;
      }
      // cout << "#1" << endl;
    } else if (runLeft <= left and runRight >= left and runRight <= right) {
      right = runRight;
      maxVal += k;
      // cout << "#1" << endl;
    } else if (runLeft >= left and runLeft <= right and runRight >= right) {
      left = runLeft;
      maxVal += k;
      // cout << "#1" << endl;
    } else if (runLeft > left and runRight < right) {
      left = runLeft;
      right = runRight;
      maxVal += k;
      // cout << "#1" << endl;
    } else if (runRight > right and runLeft > right) {
      if (k > maxVal) {
        maxVal = k;
        left = runLeft;
        right = runRight;
      }
      // cout << "#1" << endl;
    }
     debug3(left, right, maxVal);
     ckk;
  }
  return maxVal;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  vector<vector<int>> queries;
  cin >> q >> q;
  for (int i = 0; i < q; ++i) {
    vector<int> tmp(3);
    cin >> tmp[0] >> tmp[1] >> tmp[2];
    queries.push_back(tmp);
  }

  cout << arrayManipulation(queries) << endl;

  return 0;
}
