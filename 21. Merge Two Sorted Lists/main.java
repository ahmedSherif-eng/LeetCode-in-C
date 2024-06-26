/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if(list1 == null)
         {
            if(list2 == null)
                return null;
            else 
                return list2;
         }
         else if(list2 == null)
         {
            if(list1 == null)
                return null;
            else 
                return list1;
         }
        ListNode result = new ListNode(); 
        if(list1.val < list2.val)
        {
            result.val = list1.val;
            list1 = list1.next;
        }
        else
        {
            result.val = list2.val;
            list2 = list2.next; 
        }
        ListNode head =result; 
        while(list1 != null || list2 != null)
        {   
            if(list1 == null)
            {
                result.next = list2;
                break;
            }
            else if (list2 == null)
            {
               result.next = list1;
               break;
            }
            else{
                if(list1.val < list2.val)
                {
                    result.next = list1;
                    result = result.next;
                    list1 = list1.next;
                }
                else
                {
                    result.next = list2;
                    result = result.next;
                    list2 = list2.next;
                }
            }
        }
        return head;
    }

}