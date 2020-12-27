class Solution {
  public:
    bool isPalindrome(int x) {
      if(x < 0) return false;
      long long tmp = x, rev = 0;
      while(tmp > 0){
        rev = rev * 10 + tmp % 10;
        tmp /= 10;
      }
      return rev == x;
    }
};
