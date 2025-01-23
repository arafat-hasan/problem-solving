class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        container = {}

        for i, num in enumerate(nums):
            if target - num in container:
                return [container[target - num], i]
            container[num] = i
            return
