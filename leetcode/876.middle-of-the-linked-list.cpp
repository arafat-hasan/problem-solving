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
  ListNode* middleNode(ListNode* head) {
    if (head == nullptr) return head;

    ListNode* hare = head;
    ListNode* tortoise = head;

    while (hare->next != nullptr and hare->next->next != nullptr) {
      hare = hare->next->next;
      tortoise = tortoise->next;
    }
    return hare->next != nullptr ? tortoise->next : tortoise;
  }
};
// @leet end

int main() {}
