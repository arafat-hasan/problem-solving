/*
 * FILE: 2119.a_number_after_a_double_reversal.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/a-number-after-a-double-reversal/
 * DATE CREATED: 13-01-22 01:30:25 (+06)
 * LAST MODIFIED: 13-01-22 01:31:14 (+06)
 * VERDICT: Accepetd
 */

class Solution {
public:
    bool isSameAfterReversals(int num) {
      return num % 10 != 0 or num == 0;
    }
};
