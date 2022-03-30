/*
 * FILE: 165.compare_version_numbers.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/compare-version-numbers/
 * DATE CREATED: 25-02-22 15:33:21 (+06)
 * LAST MODIFIED: 25-02-22 16:02:30 (+06)
 * VERDICT: Accepetd
 */

// class Solution {
//  public:
//   Solution() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//   }

//  int compareVersion(string version1, string version2) {
//    vector<int> verList1, verList2;
//    split(version1, &verList1);
//    split(version2, &verList2);

//    for (int i = 0; i < verList1.size() or i < verList2.size(); ++i) {
//      int item1 = i >= verList1.size() ? 0 : verList1[i];
//      int item2 = i >= verList2.size() ? 0 : verList2[i];

//      if (item1 < item2) return -1;
//      if (item2 < item1) return 1;
//    }

//    return 0;
//  }

// private:
//  void split(string s, vector<int>* res) {
//    stringstream ss(s);
//    string item;
//    while (getline(ss, item, '.')) {
//      res->push_back(stoi(item));
//    }
//  }
//};

class Solution {
 public:
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  }

  int compareVersion(string version1, string version2) {
    for (auto &w : version1)
      if (w == '.') w = ' ';
    for (auto &w : version2)
      if (w == '.') w = ' ';
    istringstream s1(version1), s2(version2);

    while (1) {
      int n1, n2;
      if (not(s1 >> n1)) n1 = 0;
      if (not(s2 >> n2)) n2 = 0;

      if (not s1 and not s2) return 0;
      if (n1 < n2) return -1;
      if (n2 < n1) return 1;
    }
  }
};
