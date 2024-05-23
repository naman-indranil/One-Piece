public class reverseLinkedList {
    public ListNode reverseList(ListNode head) {
        ListNode curr = head;
        ListNode skip = null;
        while(head != null){
            curr = head.next;
            head.next= skip;
            skip = head;
            head=curr;
        }
        return skip;
    }
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
}
