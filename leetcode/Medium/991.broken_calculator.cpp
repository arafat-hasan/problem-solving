/*
 * FILE: 991.broken_calculator.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/broken-calculator/
 * DATE CREATED: 23-03-22 11:32:04 (+06)
 * LAST MODIFIED: 23-03-22 13:00:56 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  int brokenCalc(int startValue, int target) {
    int res = 0;
    while (target > startValue) {
      if (target & 1) {
        target++;
      } else {
        target /= 2;
      }
      res++;
    }

    return res + startValue - target;
  }
};
