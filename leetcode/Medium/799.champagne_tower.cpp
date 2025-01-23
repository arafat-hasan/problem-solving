/*
 * FILE: 799.champagne_tower.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/champagne-tower/
 * DATE CREATED: 04-03-22 17:52:22 (+06)
 * LAST MODIFIED: 04-03-22 22:32:37 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  double champagneTower(int poured, int query_row, int query_glass) {
    int gridSize = 102;
    vector<vector<double>> grid(gridSize, vector<double>(gridSize));
    grid[1][1] = poured * 1.0;
    for (int i = 2; i < gridSize; ++i) {
      for (int j = 1; j <= i; ++j) {
        if (grid[i - 1][j] > 1) {
          grid[i][j] += (grid[i - 1][j] - 1) / 2;
          grid[i - 1][j] -= grid[i][j];
        }
        if (grid[i - 1][j - 1] > 1) {
          grid[i][j] += grid[i - 1][j - 1] - 1;
          grid[i - 1][j - 1] = 1;
        }
        if (i == query_row + 1 && j == query_glass + 1 and grid[i][j] <= 1)
          return grid[query_row + 1][query_glass + 1];
      }
    }

    return grid[query_row + 1][query_glass + 1];
  }
};
