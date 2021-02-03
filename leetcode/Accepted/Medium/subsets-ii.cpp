/*
 * FILE: subsets-ii.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/subsets-ii/
 * DATE CREATED: 03-02-21 16:30:02 (+06)
 * LAST MODIFIED: 03-02-21 17:04:25 (+06)
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

class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int bitmask = 0;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    bool flag = true;
    while (true) {
      vector<int> set;
      for (int i = 0; i <= 30; i++) {
        if (bitchk(bitmask, i)) {
          if (i >= (int)nums.size()) {
            flag = false;
            break;
          } else {
            set.push_back(nums[i]);
          }
        }
      }
      if (flag == false) break;
      ans.push_back(set);
      bitmask++;
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> v = {1, 2, 2};
  Solution obj;
  vector<vector<int>> powerset = obj.subsetsWithDup(v);
  for (vector<int> set : powerset) {
    for (int elem : set) {
      cout << elem << ' ';
    }
    cout << endl;
  }

  return 0;
}
