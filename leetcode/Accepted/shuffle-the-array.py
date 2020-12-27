class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        result = []

        for i in range(2*n):
            result.append(nums[i//2] if i%2 == 0 else nums[n+i//2])

        return result
