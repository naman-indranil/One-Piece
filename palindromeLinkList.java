public class palindromeLinkList {
    public boolean isPalindrome(ListNode head) {
        ListNode rev = null;
        ListNode temp = head , prev = null;
        while(temp.next != null){
            ListNode curr = new ListNode(temp.val, prev);
            prev = curr;
            temp = temp.next;
        }
        if(temp != null){
            ListNode curr = new ListNode(temp.val, prev);
            rev = curr;
        } else {
        rev = temp;
        }
        while(head != null && rev != null){
            if(head.val != rev.val) {
                return false;
            }
            head = head.next;
            rev = rev.next;
        }
        return true;
    }
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
}
