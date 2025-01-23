/*
 * FILE: 567.permutation_in_string.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/permutation-in-string/
 * DATE CREATED: 12-02-22 01:12:42 (+06)
 * LAST MODIFIED: 12-02-22 02:22:05 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    map<char, int> s1Hash, s2Hash;
    int window = (int)s1.size();
    int len = (int)s2.size();
    if (window > len) return false;
    int right = 0, left = 0;
    while (right < window) {
      s1Hash[s1[right]]++;
      s2Hash[s2[right]]++;
      right++;
    }
    right--;

    while (right < len) {
      if (s1Hash == s2Hash) {
        return true;
      }

      right++;

      if (right != len) {
        s2Hash[s2[left]]--;
        s2Hash[s2[right]]++;
        if (s2Hash[s2[left]] == 0) s2Hash.erase(s2[left]);
      }
      left++;
    }
    return false;
  }
};
