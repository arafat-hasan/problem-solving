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
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr) return head;

    ListNode* curr = head->next;
    ListNode* prev = head;
    ListNode* next_curr;
    head->next = nullptr;

    while (curr != nullptr) {
      next_curr = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next_curr;
    }

    return prev;
  }
};
// @leet end

int main() {}
