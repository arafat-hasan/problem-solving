/*
 * FILE: 392.is_subsequence.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/is-subsequence/submissions/
 * DATE CREATED: 26-01-21 01:27:00 (+06)
 * LAST MODIFIED: 02-03-22 23:36:39 (+06)
 * VERDICT: Accepetd
 */

// class Solution {
//  public:
//   bool isSubsequence(string s, string t) {
//     if ((int)t.size() == 0 and (int) s.size() == 0) return true;
//     bool flag = false;
//     for (int i = 0, subPos = 0; i < (int)t.size(); ++i) {
//       if (t[i] == s[subPos]) {
//         subPos++;
//       }
//       if (subPos == (int)s.size()) {
//         flag = true;
//         break;
//       }
//     }
//     return flag;
//   }
// };

// Accepted 0ms
class Solution {
 public:
  bool isSubsequence(string s, string t) {
    return lcs(s, t, s.size(), t.size());
  }

 private:
  bool lcs(string &s, string &t, int m, int n) {
    if (m == 0) return true;
    if (n == 0) return false;

    if (s[m - 1] == t[n - 1]) return lcs(s, t, m - 1, n - 1);
    return lcs(s, t, m, n - 1);
  }
};
