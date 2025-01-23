/*
 * FILE: 2114.maximum_number_of_words_found_in_sentences.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/
 * DATE CREATED: 13-01-22 01:43:56 (+06)
 * LAST MODIFIED: 13-01-22 01:44:23 (+06)
 * VERDICT: Accepetd
 */


class Solution {
 public:
  int mostWordsFound(vector<string>& sentences) {
    int maxLen = 0;
    for (string sentence : sentences) {
      int count = wordCount(&sentence);
      maxLen = count > maxLen ? count : maxLen;
    }
    return maxLen;
  }

 private:
  int wordCount(string* sentence) {
    int count = 0;
    string item;
    stringstream ss;
    ss << (*sentence);
    while (ss >> item) {
      count++;
    }
    return count;
  }
};
