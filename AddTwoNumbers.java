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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ans = new ListNode(0);
        ListNode curr = ans;
        int carry = 0,sum=0;
        while(l1!=null && l2!=null){
            sum = l1.val+l2.val+carry;
            if(sum>9){
                carry = sum/10;
                sum = sum%10;
            } else{
                carry = 0;
            }
            curr.next = new ListNode(sum);
            curr = curr.next;
            l1=l1.next;
            l2=l2.next;
            sum=0;
        }
        if(l1!=null){
            while(l1!=null){
            sum = l1.val+carry;
            if(sum>9){
                carry = sum/10;
                sum = sum%10;
            }else{
                carry=0;
            }
            curr.next = new ListNode(sum);
            curr = curr.next;
            l1=l1.next;
                sum=0;
            }
        }
        
        if(l2!=null){
            while(l2!=null){
            sum = l2.val+carry;
            if(sum>9){
                carry = sum/10;
                sum = sum%10;
            } else{
                carry=0;
            }
            curr.next = new ListNode(sum);
            curr = curr.next;
            l2=l2.next;
                sum=0;
            }
        }
        if(carry!=0)
        curr.next = new ListNode(carry);
        
        return ans.next;
    }
}
