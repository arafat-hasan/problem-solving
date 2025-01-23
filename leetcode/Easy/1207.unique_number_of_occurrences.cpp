/*
 * FILE: 1207.unique_number_of_occurrences.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/unique-number-of-occurrences
 * DATE CREATED: 30-11-22 11:49:33 (+06)
 * LAST MODIFIED:
 * VERDICT: Accepetd
 */

class Solution {
 public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> freq;
    unordered_set<int> st;
    for (auto i : arr) freq[i]++;
    for (auto i : freq) st.insert(i.second);
    return st.size() == freq.size();
  }
};
