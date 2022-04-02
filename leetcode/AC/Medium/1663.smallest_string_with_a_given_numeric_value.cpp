/*
 * FILE: 1663.smallest_string_with_a_given_numeric_value.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK:
 * https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
 * DATE CREATED: 23-03-22 00:43:33 (+06)
 * LAST MODIFIED: 23-03-22 00:45:20 (+06)
 * VERDICT: Accepetd
 */

// Accepted 195ms
//class Solution {
// public:
//  string getSmallestString(int n, int k) {
//    vector<int> v;

//    int need = k;

//    for (int pos = n; pos > 0; --pos) {
//      int taken = 26;
//      int rest = pos - 1;

//      while (need - taken < rest) {
//        taken--;
//      }
//      v.push_back(taken);
//      need -= taken;
//    }

//    string res;
//    for (int i = v.size() - 1; i >= 0; --i) res += (int)'a' + v[i] - 1;
//    return res;
//  }
//};



class Solution {
 public:
  string getSmallestString(int n, int k) {
    vector<int> v;

    int need = k;
    int rest = n;

    for(int i = 26; i > 0; --i){


    }

    string res;
    for (int i = v.size() - 1; i >= 0; --i) res += (int)'a' + v[i] - 1;
    return res;
  }
};
