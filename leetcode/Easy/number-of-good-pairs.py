class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        freqDict = Counter(nums)
        ans = 0
        for key in freqDict:
            freq = freqDict[key]
            ans += (freq*(freq-1))//2

        return ans
