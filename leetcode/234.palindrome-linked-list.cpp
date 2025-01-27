#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
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
  bool isPalindrome(ListNode *head) {
    stack<int> st;
    ListNode *curr = head;

    while (curr != nullptr) {
      st.push(curr->val);
      curr = curr->next;
    }

    curr = head;
    while (curr != nullptr) {
      if (curr->val != st.top()) return false;
      curr = curr->next;
      st.pop();
    }
    return true;
  }
};

class Solution2 {
  ListNode *curr;

 public:
  bool isPalindrome(ListNode *head) {
    curr = head;
    return solve(head);
  }

  bool solve(ListNode *head) {
    if (head == nullptr) return true;
    bool ans = solve(head->next);
    ans = ans and (head->val == curr->val);
    curr = curr->next;
    return ans;
  }
};

// @leet start
class Solution {
  ListNode *reverse(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next_curr;
    while (curr != nullptr) {
      next_curr = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next_curr;
    }
    return prev;
  }

  ListNode *middleNode(ListNode *head) {
    ListNode *hare = head;
    ListNode *tortoise = head;
    while (hare != nullptr and hare->next != nullptr) {
      tortoise = tortoise->next;
      hare = hare->next->next;
    }
    return tortoise;
  }

 public:
  bool isPalindrome(ListNode *head) {
    ListNode *mid = middleNode(head);
    ListNode *rev = reverse(mid);
    while (rev) {
      if (rev->val != head->val) return false;
      rev = rev->next;
      head = head->next;
    }
    return true;
  }
};
// @leet end

int main() {}
