class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """

        res = 0
        if x >= 0:
            flag = True
        else:
            flag = False
            x = -x

        while x is not 0:
            res = (res * 10) + x % 10
            x = x/10

        res = 0 if res > 2147483647 else res
        res = -res if flag is False else res
        return res;
