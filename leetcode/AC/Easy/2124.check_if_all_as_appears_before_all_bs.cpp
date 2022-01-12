/*
 * FILE: 2124.check_if_all_as_appears_before_all_bs.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
 * DATE CREATED: 12-01-22 18:09:54 (+06)
 * LAST MODIFIED: 12-01-22 18:10:50 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  bool checkString(string s) {
    bool bFoundBefore = false;
    for (char item : s) {
      if (item == 'b') {
        bFoundBefore = true;
      } else if (item == 'a' and bFoundBefore == true) {
        return false;
      }
    }
    return true;
  }
};
