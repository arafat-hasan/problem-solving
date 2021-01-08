class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        result = []
        for i in range(1, len(nums), 2):
            for j in range(0, nums[i-1]):
                result.append(nums[i])

        return result

