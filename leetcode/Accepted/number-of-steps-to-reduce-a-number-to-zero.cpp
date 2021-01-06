class Solution {
  public:
    int numberOfSteps (int num) {
      int steps = 0;
      while(num != 0){
        num = num&1? num-1 : num/2;
        steps++;
      }
      return steps;
    }
};
