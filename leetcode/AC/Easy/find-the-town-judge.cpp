/*
 * FILE: find-the-town-judge.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/find-the-town-judge/
 * DATE CREATED: 03-01-22 18:21:20 (+06)
 * LAST MODIFIED: 03-01-22 22:05:46 (+06)
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

class Solution {
 public:
  int findJudge(int n, vector<vector<int>>& trust) {
    if(trust.size() == 0 and n == 1) return 1;
    map<int, vector<int>> trustedBy;
    map<int, vector<int>> trustTo;
    for (auto i : trust) {
      trustedBy[i[1]].push_back(i[0]);
      trustTo[i[0]].push_back(i[1]);
    }

    vector<int> trustedByAllIdx;
    for (auto i : trustedBy) {
      if (i.second.size() == n - 1) trustedByAllIdx.push_back(i.first);
    }

    int judgeCount = 0, ansIdx;
    for (int i : trustedByAllIdx) {
      if (trustTo[i].size() == 0) {
        judgeCount++;
        ansIdx = i;
      }
    }
    return (judgeCount == 1 ? ansIdx : -1);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  Solution obj;
  int n, trustPair;
  cin >> n >> trustPair;
  vector<vector<int>> trust(trustPair);
  for (int i = 0; i < trustPair; i++) {
    int a, b;
    cin >> a >> b;
    trust[i] = {a, b};
  }
  cout << obj.findJudge(n, trust) << endl;

  return 0;
}
