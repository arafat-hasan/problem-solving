class Solution:
    def findLength(self, A: List[int], B: List[int]) -> int:
        dp = [[0 for i in range(1001)] for j in range(1001)]
        result = 0
        for i in range(len(A)+1):
            for j in range(len(B)+1):
                if i is 0 or j is 0:
                    dp[i][j] = 0
                elif A[i-1] == B[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                    result = max(result, dp[i][j])
                else:
                    dp[i][j] = 0

        return result
