class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        ans = 0
        n = len(arr)
        for i in range(n):
            occur = ceil(((i+1)*(n-i))/2.0)
            ans += (occur * arr[i])

        return ans
