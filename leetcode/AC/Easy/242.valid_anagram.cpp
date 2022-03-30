/*
 * FILE: 242.valid_anagram.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/valid-anagram/
 * DATE CREATED: 12-02-22 02:25:05 (+06)
 * LAST MODIFIED: 12-02-22 02:25:18 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  bool isAnagram(string s, string t) {
    vector<int> sHash(26, 0), tHash(26, 0);
    if (s.size() != t.size()) return false;
    for (int i = 0; i < (int)s.size(); ++i) {
      sHash[s[i] - 'a']++;
      tHash[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
      if (sHash[i] != tHash[i]) {
        return false;
      }
    }
    return true;
  }
};

// class Solution {
//  public:
//   bool isAnagram(string s, string t) {
//     sort(s.begin(), s.end());
//     sort(t.begin(), t.end());
//     return t == s;
//   }
// };
