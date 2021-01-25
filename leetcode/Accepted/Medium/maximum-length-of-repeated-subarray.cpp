class Solution {
 public:
  int findLength(vector<int>& A, vector<int>& B) {
    int dp[1001][1001], result = 0;
    for (int i = 0; i <= (int)A.size(); ++i) {
      for (int j = 0; j <= (int)B.size(); ++j) {
        if (i == 0 or j == 0) {
          dp[i][j] = 0;
        } else if (A[i - 1] == B[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          result = max(result, dp[i][j]);
        } else {
          dp[i][j] = 0;
        }
      }
    }
    return result;
  }
};
