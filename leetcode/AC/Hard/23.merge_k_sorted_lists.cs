
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
  public ListNode MergeKLists(ListNode[] lists) {
    if(!lists.Any()) return null;

    List<ListNode> lst = lists.Cast<ListNode>().ToList();

    while(lst.Count() > 1){
      lst.Add(mergeTwoLists(lst[0], lst[1]));
      lst.RemoveAt(0);
      lst.RemoveAt(0);
    }
    return lst.First();
  }

  ListNode mergeTwoLists(ListNode l1, ListNode l2){
    if(l1 == null) {
      return l2;
    }
    if(l2 == null) {
      return l1;
    }

    if(l1.val <= l2.val){
      l1.next = mergeTwoLists(l1.next, l2);
      return l1;
    }else{
      l2.next = mergeTwoLists(l2.next, l1);
      return l2;
    }
  }
}
