class Solution {
 public:
  int numSquares(int n) {
    int* dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
      dp[i] = i;
      for (int x = 1; x * x <= i; x++) {
        int tmp = x * x;
        if (tmp > i) {
          break;
        } else {
          dp[i] = min(dp[i], 1 + dp[i - tmp]);
        }
      }
    }

    int res = dp[n];
    delete[] dp;

    return res;
  }
};
