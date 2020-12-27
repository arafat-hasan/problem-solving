class Solution {
  public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
      int mx = *max_element(candies.begin(), candies.end());
      vector<bool> res;
      for(int item : candies){
        res.push_back(item+extraCandies >= mx? true : false);
      }
      return res;
    }
};
