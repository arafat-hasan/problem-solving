class Solution {
  public:
    string restoreString(string s, vector<int>& indices) {
      string result = s;
      for(int i = 0; i < (int) s.size(); ++i){
        result[indices[i]] = s[i];
      }
      return result;
    }
};
