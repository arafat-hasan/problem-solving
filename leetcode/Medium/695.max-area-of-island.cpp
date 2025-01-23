/*
 * FILE: max-area-of-island.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/max-area-of-island
 * DATE CREATED: 03-07-21 21:01:55 (+06)
 * LAST MODIFIED: 09-07-21 15:14:28 (+06)
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
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  int rowLimit, colLimit;
  int bug = 0;
  vector<vector<int>>* grid;
  vector<vector<bool>> visited;

 private:
  bool isSafe(int row, int col) {
    return (row >= 0) and (col >= 0) and (row < rowLimit) and (col < colLimit);
  }

  int dfs2D(int row, int col) {
    visited[row][col] = true;

    int sum = 0;
    for (int i = 0; i < 4; ++i) {
      int row_ = row + dy[i];
      int col_ = col + dx[i];
      if (isSafe(row_, col_) and (*grid)[row_][col_] == 1 and
          visited[row_][col_] == false) {
        sum += dfs2D(row_, col_);
      }
    }
    return sum + 1;
  }

 public:
  int maxAreaOfIsland(vector<vector<int>>& _grid) {
    grid = &_grid;
    rowLimit = (int)(*grid).size();
    colLimit = (int)(*grid)[0].size();
    visited = vector<vector<bool>>(rowLimit, vector<bool>(colLimit, false));
    int mx = 0;
    for (int i = 0; i < rowLimit; ++i) {
      for (int j = 0; j < colLimit; ++j) {
        if (((*grid)[i][j] == 1) and (visited[i][j] != true)) {
          mx = max(mx, dfs2D(i, j));
        }
      }
    }

    return mx;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  Solution obj;
  int row, col, tmp;
  cin >> row >> col;
  vector<vector<int>> grid(row);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cin >> tmp;
      grid[i].push_back(tmp);
    }
  }

  cout << obj.maxAreaOfIsland(grid) << endl;
  return 0;
}
