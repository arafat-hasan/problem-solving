/*
 * FILE: 1910.remove_all_occurrences_of_a_substring.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
 * DATE CREATED: 03-03-22 00:43:12 (+06)
 * LAST MODIFIED: 03-03-22 00:53:34 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  string removeOccurrences(string s, string part) {
    while (true) {
      size_t found = s.find(part);
      if (found == string::npos) break;
      s.erase(found, part.size());
    }
    return s;
  }
};
