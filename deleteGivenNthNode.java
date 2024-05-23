public class deleteGivenNthNode {
    public void deleteNode(ListNode node) {
        ListNode prev  = node.next;
        node.val = prev.val;
        node.next = prev.next;
    }
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
}
