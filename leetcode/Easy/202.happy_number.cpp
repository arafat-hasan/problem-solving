/*
 * FILE: 202.happy_number.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/happy-number/
 * DATE CREATED: 08-02-22 16:43:51 (+06)
 * LAST MODIFIED: 08-02-22 16:57:26 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  bool isHappy(int n) {
    int ans = n;
    for (int i = 1; i < 100; i++) {
      ans = squareOfDigits(ans);
      if (ans == 1) break;
    }
    return ans == 1 ? 1 : 0;
  }

 private:
  void splitDigits(int n, vector<int>& res) {
    while (n > 0) {
      res.push_back(n % 10);
      n /= 10;
    }
  }

  int squareOfDigits(int n) {
    vector<int> digits;
    splitDigits(n, digits);
    int sum = 0;
    for (int i : digits) sum += i * i;
    return sum;
  }
};
