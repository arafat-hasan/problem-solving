/*
 * FILE: 20.valid_parentheses.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/valid-parentheses/
 * DATE CREATED: 02-03-21 16:23:14 (+06)
 * LAST MODIFIED: 13-03-22 12:53:24 (+06)
 * VERDICT: Accepetd
 */

// class Solution {
//  public:
//   bool isValid(string s) {
//     stack<char> paren;

//    for (char c : s) {
//      if (c == '(' or c == '{' or c == '[') {
//        paren.push(c);
//      } else {
//        if (paren.empty())
//          return false;
//        else if (c == ')' and paren.top() != '(')
//          return false;
//        else if (c == '}' and paren.top() != '{')
//          return false;
//        else if (c == ']' and paren.top() != '[')
//          return false;
//        paren.pop();
//      }
//    }
//    return paren.empty();
//  }
//};

class Solution {
 public:
  bool isValid(string s) {
    if (s.size() & 1) return false;

    stack<char> stck;
    for (char i : s) {
      if (i == '(' or i == '{' or i == '[') {
        stck.push(i);
      } else {
        if (stck.empty() or (i == ')' and stck.top() != '(') or
            (i == '}' and stck.top() != '{') or
            (i == ']' and stck.top() != '[')) {
          return false;
        }
        stck.pop();
      }
    }
    return stck.empty();
  }
};
