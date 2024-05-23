public class middleOfLinkedList {
    public ListNode middleNode(ListNode head) {
        ListNode fast = head , slow = head;
        int c=0;
        while(fast.next != null && fast.next.next != null){
            fast=fast.next.next;
            slow=slow.next;
            c++;
        }
        if(fast.next != null)
        slow=slow.next;
        return slow;
    }

    public class ListNode {
             int val;
             ListNode next;
             ListNode() {}
             ListNode(int val) { this.val = val; }
             ListNode(int val, ListNode next) { this.val = val; this.next = next; }
         }
}
