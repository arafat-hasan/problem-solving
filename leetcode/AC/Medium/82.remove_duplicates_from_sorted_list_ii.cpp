/*
 * FILE: 82.remove_duplicates_from_sorted_list_ii.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 * DATE CREATED: 09-03-22 12:50:17 (+06)
 * LAST MODIFIED: 09-03-22 16:52:03 (+06)
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
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return nullptr;

    ListNode newHead = ListNode();
    newHead.next = head;

    ListNode* prev = &newHead;
    ListNode* cur = head;
    ListNode* akshi = head;

    while (cur != nullptr) {
      while (akshi != nullptr) {
        if (cur->val != akshi->val) {
          break;
        }
        akshi = akshi->next;
      }

      if (cur->next == akshi) {
        cur = cur->next;
        akshi = cur;
        prev = prev->next;
      } else {
        prev->next = akshi;
        cur = akshi;
      }
    }
    return newHead.next;
  }
};

// Accepted: 11ms
// class Solution {
// public:
//  ListNode* deleteDuplicates(ListNode* head) {
//    if (!head) return head;
//    ListNode* runner = head;
//    vector<int> v;
//    while (runner != nullptr) {
//      v.push_back(runner->val);
//      runner = runner->next;
//    }

//    map<int, int> freq;
//    for (auto i : v) freq[i]++;
//    v.clear();
//    for (auto i : freq) {
//      if (i.second == 1) v.push_back(i.first);
//    }
//    if (v.size() == 0) return nullptr;

//    ListNode* node = new ListNode();
//    ListNode* ret = node;
//    for (int i = 0; i < (int)v.size(); ++i) {
//      node->val = v[i];
//      if (i != v.size() - 1) {
//        node->next = new ListNode();
//        node = node->next;
//      }
//    }
//    return ret;
//  }
//};
