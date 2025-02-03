/*
 * FILE: 2.add_two_numbers.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/add-two-numbers/
 * DATE CREATED: 08-02-22 21:26:10 (+06)
 * LAST MODIFIED: 11-03-22 01:46:49 (+06)
 * VERDICT: Accepetd
 */

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


// Accepetd 57ms
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode();
    ListNode* copyHead = head;
    int carry = 0;
    while (carry != 0 || l1 != nullptr || l2 != nullptr) {
      int l1Val = 0, l2Val = 0;
      if (l1 != nullptr) {
        l1Val = l1->val;
        l1 = l1->next;
      }

      if (l2 != nullptr) {
        l2Val = l2->val;
        l2 = l2->next;
      }

      int sum = l1Val + l2Val + carry;
      carry = sum / 10;
      sum %= 10;
      ListNode* node = new ListNode(sum);
      copyHead->next = node;
      copyHead = copyHead->next;
    }
    return head->next;
  }
};
