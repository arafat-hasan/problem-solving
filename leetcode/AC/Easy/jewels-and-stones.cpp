class Solution {
  public:
    int numJewelsInStones(string jewels, string stones) {
      int count = 0;
      for(char jewel : jewels){
        for(char stone : stones){
          if(jewel == stone) count++;
        }
      }
      return count;
    }
};
