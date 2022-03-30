/*
 * FILE: 438.find_all_anagrams_in_a_string.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/find-all-anagrams-in-a-string/
 * DATE CREATED: 03-02-22 02:25:48 (+06)
 * LAST MODIFIED: 03-02-22 03:03:09 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> pHash(26, 0);
    vector<int> hash(26, 0);
    int window = (int)p.size();
    int len = (int)s.size();
    vector<int> ans;

    if (len < window) return ans;

    int left = 0, right = 0;

    while (right < window) {
      pHash[p[right] - 'a'] += 1;
      hash[s[right] - 'a'] += 1;
      right++;
    }
    right--;

    while (right < len) {
      if (pHash == hash) {
        ans.push_back(left);
      }

      right++;

      if (right != len) {
        hash[s[left - 1] - 'a'] -= 1;
        hash[s[right] - 'a'] += 1;
      }
      left++;
    }

    return ans;
  }
};
