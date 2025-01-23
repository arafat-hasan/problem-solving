/*
 * FILE: 402.remove_k_digits.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/remove-k-digits/
 * DATE CREATED: 18-02-22 16:34:46 (+06)
 * LAST MODIFIED: 18-02-22 23:46:14 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  string removeKdigits(string num, int k) {
    stack<char> stck;

    for (int i = 0; i < (int)num.size(); ++i) {
      if (stck.empty() && num[i] == '0') continue;

      if (k == 0 || stck.empty() || stck.top() <= num[i]) {
        stck.push(num[i]);
        continue;
      }

      while (k > 0 && !stck.empty() && stck.top() > num[i]) {
        stck.pop();
        k--;
      }
      if (!stck.empty() || num[i] != '0') stck.push(num[i]);
    }

    while (k > 0 and !stck.empty()) {
      stck.pop();
      k--;
    }

    if (stck.empty()) return "0";
    string ans;
    while (!stck.empty()) {
      ans += stck.top();
      stck.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

// Accepetd: 24ms
// class Solution {
// public:
//  string removeKdigits(string num, int k) {
//    int pivot = 0;
//    while (k--) {
//      for (int i = pivot; i < (int)num.size() - 1; ++i) {
//        if (num[i + 1] < num[i]) {
//          break;
//        }
//        pivot++;
//      }

//      num.erase(num.begin() + pivot);
//      pivot -= pivot != 0;
//      while (num[0] == '0' and num.size() > 0) {
//        num.erase(num.begin());
//      }
//      if (num.size() == 0) break;
//    }
//    return num.size() == 0 ? "0" : num;
//  }
//};
