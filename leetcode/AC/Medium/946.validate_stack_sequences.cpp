/*
 * FILE: 946.validate_stack_sequences.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/validate-stack-sequences/
 * DATE CREATED: 16-03-22 13:35:06 (+06)
 * LAST MODIFIED: 16-03-22 15:30:38 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
    int popCur = 0, i = 0;
    for (i = 0; i < pushed.size(); ++i) {
      st.push(pushed[i]);
      while (popped[popCur] == st.top()) {
        popCur++;
        st.pop();
        if (st.empty()) break;
      }
    }
    return popCur == pushed.size() && i == pushed.size();
  }
};
