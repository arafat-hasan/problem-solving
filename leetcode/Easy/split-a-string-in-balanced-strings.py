class Solution:
    def balancedStringSplit(self, s: str) -> int:
        res = 0
        count = 0
        for item in s:
            res += 1 if item is 'R' else -1
            count += res is 0

        return count
