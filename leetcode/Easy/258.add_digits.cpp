/*
 * FILE: 258.add_digits.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/add-digits/
 * DATE CREATED: 08-02-22 16:13:12 (+06)
 * LAST MODIFIED: 08-02-22 16:13:42 (+06)
 * VERDICT: Accepetd
 */

class Solution {
public:
    int addDigits(int num) {
      while(num > 9){
        num = digitSum(num);
      }
      return num; 
    }
private:
    int digitSum(int n){
      int sum = 0;
      while(n > 0){
        sum += n % 10;
        n /= 10;
      }
      return sum;
    }
};
