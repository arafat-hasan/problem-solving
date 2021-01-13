class Solution:
    def numSquares(self, n: int) -> int:
        dp = [i for i in range(n+1)]
        for i in range(4, n+1):
            x = 1
            while x * x <= i:
                tmp = x * x
                if tmp > i:
                    break
                else:
                    dp[i] = min(dp[i], 1 + dp[i - tmp])
                x += 1

        return dp[n]
