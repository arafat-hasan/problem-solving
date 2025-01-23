/*
 * FILE: 211.design_add_and_search_words_data_structure.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK:
 * https://leetcode.com/problems/design-add-and-search-words-data-structure/
 * DATE CREATED: 30-01-22 01:04:29 (+06)
 * LAST MODIFIED: 30-01-22 01:04:47 (+06)
 * VERDICT: Accepetd
 */

class WordDictionary {
 public:
  WordDictionary() {}

  void addWord(string word) { words[word.size()].push_back(word); }

  bool search(string word) {
    for (auto s : words[(int)word.size()]) {
        if(isEqual(word, s)) return true;
    }
    return false;
  }

 private:
  unordered_map<int, vector<string>> words;
  bool isEqual(string a, string b) {
    for (int i = 0; i < (int)a.size(); i++) {
      if (a[i] == '.') continue;
      if (a[i] != b[i]) return false;
    }
    return true;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
