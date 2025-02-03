class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        count = 0
        for word in words:
            flag = True
            for char in word:
                if char not in allowed:
                    flag = False
                    break

            if flag is True:
                count += 1

        return count
