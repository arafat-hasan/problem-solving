class Solution {
 public:
  int findLength(vector<int>& A, vector<int>& B) {
    memset(dp, -1, sizeof(dp));
    return lcs((int)A.size(), (int)B.size(), A, B, 0);
  }

 private:
  int dp[1001][1001][1001];
  int lcs(int i, int j, vector<int>& X, vector<int>& Y, int count) {
    if (i == 0 || j == 0) {
      return count;
    }

    if (dp[i][j][count] != -1) return dp[i][j][count];

    if (X[i - 1] == Y[j - 1]) count = lcs(i - 1, j - 1, X, Y, count + 1);
    count = max(count, max(lcs(i - 1, j, X, Y, 0), lcs(i, j - 1, X, Y, 0)));
    return dp[i][j][count] = count;
  }
};
