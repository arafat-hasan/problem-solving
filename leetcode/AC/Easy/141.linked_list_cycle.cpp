/*
 * FILE: 141.linked_list_cycle.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/linked-list-cycle/
 * DATE CREATED: 08-03-22 12:47:59 (+06)
 * LAST MODIFIED: 08-03-22 12:51:18 (+06)
 * VERDICT: Accepetd
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  bool hasCycle(ListNode* head) {
    if (head == nullptr) return false;

    ListNode* hare = head;
    ListNode* tortoise = head;

    while (hare->next != nullptr && hare->next->next != nullptr) {
      hare = hare->next->next;
      tortoise = tortoise->next;
      if (tortoise == hare) return true;
    }
    return false;
  }
};
