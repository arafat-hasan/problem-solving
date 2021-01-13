class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    memset(dp, -1, sizeof(dp));
    return lcs((int)text1.size(), (int)text2.size(), text1, text2);
  }

 private:
  int dp[1001][1001];
  int lcs(int m, int n, string &X, string &Y) {
    if (m == 0 or n == 0) return 0;

    if (dp[m][n] != -1) return dp[m][n];
    if (X[m - 1] == Y[n - 1])
      return dp[m][n] = 1 + lcs(m - 1, n - 1, X, Y);
    else
      return dp[m][n] = max(lcs(m - 1, n, X, Y), lcs(m, n - 1, X, Y));
  }
};
