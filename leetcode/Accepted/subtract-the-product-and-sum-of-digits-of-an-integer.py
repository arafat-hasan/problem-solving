class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        product = 1
        sum = 0
        while n is not 0:
            tmp = n % 10
            n = int(n/10)
            product *= tmp
            sum += tmp

        return product - sum
