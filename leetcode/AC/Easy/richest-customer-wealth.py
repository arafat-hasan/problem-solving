class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        mx = 0
        for customer in accounts:
            total = 0
            for bank in customer:
                total += bank
                mx = total if total > mx else mx

        return mx
