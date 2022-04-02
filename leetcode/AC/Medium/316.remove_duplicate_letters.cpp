/*
 * FILE: 316.remove_duplicate_letters.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/remove-duplicate-letters/
 * DATE CREATED: 19-03-22 01:48:08 (+06)
 * LAST MODIFIED: 19-03-22 02:03:54 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  string removeDuplicateLetters(string s) {
    stack<char> st;
    map<char, int> freq;
    map<char, bool> isTaken;

    for (char c : s) freq[c]++;

    for (char c : s) {
      if (isTaken[c]) {
        freq[c]--;
        continue;
      }

      while (!st.empty() && st.top() >= c && freq[st.top()] >= 1) {
        isTaken[st.top()] = false;
        st.pop();
      }

      st.push(c);
      isTaken[c] = true;
      freq[c]--;
    }

    string res(st.size(), 'a');
    for (int i = st.size() - 1; i >= 0; --i) {
      res[i] = st.top();
      st.pop();
    }
    return res;
  }
};
