public class nodeOfCircularListStart {
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head , fast = head;
        ListNode ans = null;
        while(fast != null && fast.next != null && fast.next.next != null){
            fast = fast.next.next;
            slow= slow.next;
            if(slow == fast) {
                ans = head;
                break;
            }
        }
        if(ans == null){
            return ans;
        }
        while ( slow != ans){
            slow= slow.next;
            ans = ans.next;
        }
        return ans;
    }
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
}
