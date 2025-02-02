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
  ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr or head->next == nullptr) return head;
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* firstEven = head->next;
    ListNode *nextOdd, *nextEven;

    while (odd->next != nullptr and odd->next->next != nullptr) {
      nextOdd = odd->next->next;
      nextEven = even->next->next;
      odd->next = even->next;
      even->next = even->next->next;
      odd = nextOdd;
      even = nextEven;
    }

    odd->next = firstEven;

    return head;
  }
};
// @leet end

int main() {}
