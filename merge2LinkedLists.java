public class merge2LinkedLists {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode head = null;
        ListNode prev = null;
        ListNode curr = null;
        while(list1 != null && list2 != null) {
            if(list1.val < list2.val){
                curr = list1;
                if(head == null){
                    head = curr;
                    prev = curr;
                } else {
                    prev.next = curr;
                    prev = curr;
                }
                list1 = list1.next;
            } else {
                curr = list2;
                if(head == null){
                    head = curr;
                    prev = curr;
                } else {
                    prev.next = curr;
                    prev = curr;
                }
                list2 = list2.next;
            }
        }
        while(list1 != null){
            curr = list1;
                if(head == null){
                    head = curr;
                    prev = curr;
                } else {
                    prev.next = curr;
                    prev = curr;
                }
                list1 = list1.next;
        }
        while(list2 != null){
            curr = list2;
                if(head == null){
                    head = curr;
                    prev = curr;
                } else {
                    prev.next = curr;
                    prev = curr;
                }
                list2 = list2.next;
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
