#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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
class Solution1 {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int size = 0;
    ListNode* curr = head;
    while (curr != nullptr) {
      size++;
      curr = curr->next;
    }

    n = size - n - 1;
    curr = head;
    while (curr != nullptr and n > 0) {
      n--;
      curr = curr->next;
    }

    if (n == -1) {
      /*delete head;*/
      head = head->next;
    }

    if (curr->next != nullptr) {
      /*delete curr->next;*/
      curr->next = curr->next->next;
    }
    return head;
  }
};

// @leet start
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* first = head;
    ListNode* second = head;

    while (first and n) {
      first = first->next;
      n--;
    }

    if (first == nullptr) return head->next;

    while (first->next != nullptr) {
      first = first->next;
      second = second->next;
    }

    second->next = second->next->next;

    return head;
  }
};
// @leet end

int main() {}
