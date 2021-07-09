class Solution:
    def divisorGame(self, N: int) -> bool:
        return not (N & 1)
