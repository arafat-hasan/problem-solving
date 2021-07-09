class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        mx = max(candies)
        res = []
        for item in candies:
            res.append(True if item + extraCandies >= mx else False)

        return res
