/*
 * FILE: 23.merge_k_sorted_lists.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/merge-k-sorted-lists/
 * DATE CREATED: 05-02-22 22:58:21 (+06)
 * LAST MODIFIED: 05-02-22 22:58:46 (+06)
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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty()) return nullptr;

    while (lists.size() > 1) {
      lists.push_back(mergeTwoLists(lists[0], lists[1]));
      lists.erase(lists.begin());
      lists.erase(lists.begin());
    }
    return lists.front();
  }

  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) {
      return l2;
    }
    if (l2 == nullptr) {
      return l1;
    }

    if (l1->val <= l2->val) {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    } else {
      l2->next = mergeTwoLists(l2->next, l1);
      return l2;
    }
  }
};
