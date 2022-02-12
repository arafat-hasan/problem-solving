/*
 * FILE: 127.word_ladder.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/word-ladder/
 * DATE CREATED: 13-02-22 00:55:48 (+06)
 * LAST MODIFIED: 13-02-22 02:20:43 (+06)
 * VERDICT: Accepetd
 */

static int speedUp = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordDict(wordList.begin(), wordList.end());
    queue<string> todo;
    todo.push(beginWord);
    int ladder = 0;
    while (!todo.empty()) {
      int levelSize = todo.size();
      ladder++;
      for (int j = 0; j < levelSize; j++) {
        string word = todo.front();
        todo.pop();

        for (int i = 0; i < word.size(); i++) {
          string tmp = word;
          for (int k = 0; k < 26; k++) {
            tmp[i] = 'a' + k;
            if (word.compare(tmp) == 0) continue;

            if (wordDict.find(tmp) != wordDict.end()) {
              todo.push(tmp);
              wordDict.erase(tmp);
              if (tmp.compare(endWord) == 0) return ladder + 1;
            }
          }
        }
      }
    }
    return 0;
  }
};
