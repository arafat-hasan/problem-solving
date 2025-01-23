class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<vector<int>> pascal(rowIndex + 1);
    pascal[0].push_back(1);

    for (int row = 1; row <= rowIndex; row++) {
      for (int col = 0; col <= row; col++) {
        int top = col == row ? 0 : pascal[row - 1][col];
        int topLeft = col < 1 ? 0 : pascal[row - 1][col - 1];
        pascal[row].push_back(top + topLeft);
      }
    }

    return pascal[rowIndex];
  }
};
