/*
 * FILE: 61.rotate_list.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/rotate-list/
 * DATE CREATED: 11-03-22 16:15:14 (+06)
 * LAST MODIFIED: 11-03-22 17:45:18 (+06)
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
class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || k == 0) return head;
    ListNode* node = head;
    int len = 0;
    while (node->next != nullptr) {
      node = node->next;
      len++;
    }
    len++;
    k %= len;
    k = len - k;

    node->next = head;

    while (--k) {
      head = head->next;
    }
    node = head;
    head = head->next;
    node->next = nullptr;
    return head;
  }
};
