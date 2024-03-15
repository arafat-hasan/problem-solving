/*
 * FILE: 1844.replace-all-digits-with-characters.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/replace-all-digits-with-characters/description/
 * DATE CREATED: 27-01-23 16:36:32 (+06)
 * LAST MODIFIED: 27-01-23 16:47:42 (+06)
 * VERDICT:
 */

class Solution {
 public:
  string replaceDigits(string s) {
    for (int i = 1; i < (int)s.size(); i += 2) {
      s[i] = (char)(s[i] + s[i - 1] - '0');
    }
    return s;
  }
};
