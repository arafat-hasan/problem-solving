/*
 * FILE: 290.word_pattern.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/word-pattern/submissions/
 * DATE CREATED: 17-01-22 17:23:58 (+06)
 * LAST MODIFIED: 17-01-22 17:24:16 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  bool wordPattern(string pattern, string s) {
    vector<string> splittedWords = split(&s);
    map<char, string> aTOb;
    map<string, char> bTOa;
    if (pattern.size() != splittedWords.size()) return false;
    for (int i = 0; i < pattern.size(); i++) {
      if (aTOb.count(pattern[i]) == 0 and bTOa.count(splittedWords[i]) == 0) {
        aTOb[pattern[i]] = splittedWords[i];
        bTOa[splittedWords[i]] = pattern[i];
      } else if (aTOb[pattern[i]] != splittedWords[i] ||
                 bTOa[splittedWords[i]] != pattern[i]) {
        return false;
      }
    }
    return true;
  }

 private:
  vector<string> split(string* s) {
    vector<string> res;
    stringstream ss;
    string item;
    ss << (*s);
    while (ss >> item) {
      res.push_back(item);
    }
    return res;
  }
};
