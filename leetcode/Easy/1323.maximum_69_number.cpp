// class Solution {
// public:
//  int maximum69Number(int num) {
//    string str = to_string(num);
//    for (auto &c : str) {
//      if (c == '6') {
//        c = '9';
//        break;
//      }
//    }

//    return stoi(str);
//  }
//};

class Solution {
 public:
  int maximum69Number(int num) {
    int p = 1;
    int n = num, maxp = 0;
    while (n > 0) {
      int digit = n % 10;
      if (digit == 6) maxp = p;
      p *= 10;
      n /= 10;
    }
    return num + (maxp * 3);
  }
};
