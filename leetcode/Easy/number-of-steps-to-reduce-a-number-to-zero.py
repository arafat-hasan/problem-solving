class Solution:
    def numberOfSteps (self, num: int) -> int:
        steps = 0;
        while num is not 0:
            num = num - 1 if num&1 else int(num/2)
            steps += 1

        return steps
