#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode();
    ListNode* tail = dummyHead;

    int carry = 0;
    while (l1 != nullptr or l2 != nullptr or carry != 0) {
      int digit1 = (l1 != nullptr ? l1->val : 0);
      int digit2 = (l2 != nullptr ? l2->val : 0);
      int curr = digit1 + digit2 + carry;
      carry = curr / 10;
      curr = curr % 10;
      ListNode* newNode = new ListNode(curr);
      tail->next = newNode;
      tail = tail->next;
      l1 = (l1 != nullptr) ? l1->next : nullptr;
      l2 = (l2 != nullptr) ? l2->next : nullptr;
    }

    ListNode* result = dummyHead->next;
    delete dummyHead;
    return result;
  }
};
// @leet end

int main() {}
