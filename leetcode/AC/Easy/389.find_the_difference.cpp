/*
 * FILE: 389.find_the_difference.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/find-the-difference/
 * DATE CREATED: 08-02-22 01:09:48 (+06)
 * LAST MODIFIED: 08-02-22 01:12:03 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  }

  char findTheDifference(string s, string t) {
    int sumS = 0, sumT = 0;
    for (char i : s) sumS += (int)i;
    for (char i : t) sumT += (int)i;
    return (char)(sumT - sumS);
  }
};
