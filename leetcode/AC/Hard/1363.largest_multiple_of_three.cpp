/*
 * FILE: 1363.largest_multiple_of_three.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/largest-multiple-of-three/
 * DATE CREATED: 06-02-22 18:45:00 (+06)
 * LAST MODIFIED: 06-02-22 23:43:05 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  string largestMultipleOfThree(vector<int>& digits) {
    vector<int> digitCount(10);
    int sum = 0;
    for (int i : digits) sum += i, digitCount[i]++;

    if (sum % 3 == 2 && digitCount[2]) sum -= 2, digitCount[2]--;
    if (sum % 3 == 2 && digitCount[5]) sum -= 5, digitCount[5]--;
    if (sum % 3 == 2 && digitCount[8]) sum -= 8, digitCount[8]--;

    vector<int> singleRemoveList{1, 4, 7, 2, 5, 8};

    for (int i : singleRemoveList) {
      while (sum % 3 > 0 and digitCount[i]) digitCount[i]--, sum -= i;
    }

    if (sum == 0) return digitCount[0] ? "0" : "";

    string res;
    for (int i = 9; i >= 0; --i) {
      while (digitCount[i]) digitCount[i]--, res += '0' + i;
    }
    return res;
  }
};
