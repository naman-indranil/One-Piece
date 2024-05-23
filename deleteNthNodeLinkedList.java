public class deleteNthNodeLinkedList {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode t = head;
        ListNode prev=null;
        int len = 0;
        while(t != null){
            len++;
            t=t.next;
        }
        if(len<n){
            return head;
        } if(len == n){
            return head.next;
        }
        t = head;
        while(t != null) {
            if(len == n) {
                prev.next = t.next;
                break;
            }
            prev = t;
            t=t.next;
            len--;
        }
        return head;
    }
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
}
