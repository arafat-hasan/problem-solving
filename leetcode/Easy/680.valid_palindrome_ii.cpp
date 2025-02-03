/*
 * FILE: 680.valid_palindrome_ii.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/valid-palindrome-ii
 * DATE CREATED: 03-04-22 02:38:19 (+06)
 * LAST MODIFIED: 03-04-22 02:38:49 (+06)
 * VERDICT:
 */

class Solution {
 public:
  bool validPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;

    while (i <= j) {
      if (s[i] == s[j]) {
        i++;
        j--;
      } else
        return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
    }
    return true;
  }

  bool isPalindrome(string s, int i, int j) {
    while (i <= j) {
      if (s[i] == s[j]) {
        i++;
        j--;
      } else
        return false;
    }
    return true;
  }
};
