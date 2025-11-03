#include <bits/stdc++.h>
using namespace std;

// @leet start
class Solution {
 public:
  int countUnguarded(int m, int n, vector<vector<int>>& guards,
                     vector<vector<int>>& walls) {
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (auto i : walls) {
      grid[i[0]][i[1]] = 2;
    }

    for (auto i : guards) {
      grid[i[0]][i[1]] = 1;
    }

    bool flag;
    for (int i = 0; i < m; i++) {
      flag = false;
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          flag = true;
        } else if (grid[i][j] == 2) {
          flag = false;
        } else if (flag)
          grid[i][j] = 5;
      }
    }

    for (int i = 0; i < m; i++) {
      flag = false;
      for (int j = n - 1; j >= 0; j--) {
        if (grid[i][j] == 1) {
          flag = true;
        } else if (grid[i][j] == 2) {
          flag = false;
        } else if (flag)
          grid[i][j] = 5;
      }
    }

    for (int i = 0; i < n; i++) {
      flag = false;
      for (int j = 0; j < m; j++) {
        if (grid[j][i] == 1) {
          flag = true;
        } else if (grid[j][i] == 2) {
          flag = false;
        } else if (flag)
          grid[j][i] = 5;
      }
    }

    for (int i = 0; i < n; i++) {
      flag = false;
      for (int j = m - 1; j >= 0; j--) {
        if (grid[j][i] == 1) {
          flag = true;
        } else if (grid[j][i] == 2) {
          flag = false;
        } else if (flag)
          grid[j][i] = 5;
      }
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cnt += grid[i][j] == 0;
      }
    }
    return cnt;
  }
};

// @leet end

int main() {}
