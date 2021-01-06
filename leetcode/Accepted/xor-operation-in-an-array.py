class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        nums = [0 for i in range(n)]

        for i in range(n):
            nums[i] = start + 2 * i

        return reduce(lambda x, y: x ^ y, nums)
