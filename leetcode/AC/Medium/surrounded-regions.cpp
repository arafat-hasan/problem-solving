/*
 * FILE: surrounded-regions.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/surrounded-regions
 * DATE CREATED: 02-11-21 00:51:00 (+06)
 * LAST MODIFIED: 02-11-21 00:51:50 (+06)
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
  void solve(vector<vector<char>>& board) {
    int i, j;
    int row = board.size();
    if (!row) return;
    int col = board[0].size();

    for (i = 0; i < row; i++) {
      check(board, i, 0, row, col);
      if (col > 1) check(board, i, col - 1, row, col);
    }
    for (j = 1; j + 1 < col; j++) {
      check(board, 0, j, row, col);
      if (row > 1) check(board, row - 1, j, row, col);
    }
    for (i = 0; i < row; i++)
      for (j = 0; j < col; j++)
        if (board[i][j] == 'O') board[i][j] = 'X';
    for (i = 0; i < row; i++)
      for (j = 0; j < col; j++)
        if (board[i][j] == '1') board[i][j] = 'O';
  }
  void check(vector<vector<char>>& vec, int i, int j, int row, int col) {
    if (vec[i][j] == 'O') {
      vec[i][j] = '1';
      if (i > 1) check(vec, i - 1, j, row, col);
      if (j > 1) check(vec, i, j - 1, row, col);
      if (i + 1 < row) check(vec, i + 1, j, row, col);
      if (j + 1 < col) check(vec, i, j + 1, row, col);
    }
  }
};
