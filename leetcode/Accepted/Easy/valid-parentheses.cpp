class Solution {
 public:
  bool isValid(string s) {
    stack<char> paren;

    for (char c : s) {
      if (c == '(' or c == '{' or c == '[') {
        paren.push(c);
      } else {
        if (paren.empty())
          return false;
        else if (c == ')' and paren.top() != '(')
          return false;
        else if (c == '}' and paren.top() != '{')
          return false;
        else if (c == ']' and paren.top() != '[')
          return false;
        paren.pop();
      }
    }
    return paren.empty();
  }
};
