/*
 * FILE: 84.largest_rectangle_in_histogram.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/largest-rectangle-in-histogram/
 * DATE CREATED: 30-01-22 16:39:50 (+06)
 * LAST MODIFIED: 31-01-22 01:47:40 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int n = (int)heights.size();
    vector<int> leftSmall(n), rightSmall(n);
    stack<int> stack;

    for (int i = 0; i < n; ++i) {
      while (!stack.empty() && heights[stack.top()] >= heights[i]) stack.pop();
      if (stack.empty())
        leftSmall[i] = 0;
      else
        leftSmall[i] = stack.top() + 1;
      stack.push(i);
    }

    stack = {};
    for (int i = n - 1; i >= 0; --i) {
      while (!stack.empty() && heights[stack.top()] >= heights[i]) stack.pop();
      if (stack.empty())
        rightSmall[i] = n - 1;
      else
        rightSmall[i] = stack.top() - 1;
      stack.push(i);
    }

    int maxA = -1;
    for (int i = 0; i < n; i++) {
      maxA = max(maxA, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
    }
    return maxA;
  }
};
