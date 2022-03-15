/*
 * FILE: 1249.minimum_remove_to_make_valid_parentheses.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
 * DATE CREATED: 15-03-22 16:44:05 (+06)
 * LAST MODIFIED: 15-03-22 17:16:04 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    int count = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      char *c = &s[i];
      if (*c == '(')
        count++;
      else if (*c == ')') {
        if (count == 0) {
          *c = '-';
        } else {
          count--;
        }
      }
    }

    count = 0;
    for (int i = n - 1; i >= 0; --i) {
      char *c = &s[i];
      if (*c == ')')
        count++;
      else if (*c == '(') {
        if (count == 0) {
          *c = '-';
        } else {
          count--;
        }
      }
    }
    string res;
    for (char c : s) {
      if (c != '-') res.push_back(c);
    }
    return res;
  }
};
