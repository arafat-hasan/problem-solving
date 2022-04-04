/*
 * FILE: 1721.swapping_nodes_in_a_linked_list.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/swapping-nodes-in-a-linked-list
 * DATE CREATED: 04-04-22 18:53:42 (+06)
 * LAST MODIFIED: 04-04-22 18:54:09 (+06)
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
    ListNode* swapNodes(ListNode* head, int k) {
      vector<int> v;
      int size = 0;
      ListNode* current = head;
      while(current != null){
        v.push_back(current.val);
        current = current.next;
        size++;
      }
        
    }
};
