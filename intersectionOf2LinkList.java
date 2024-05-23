import java.util.HashSet;
import java.util.Set;

public class intersectionOf2LinkList {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Set<ListNode>  linkset = new HashSet<>();
        ListNode ans = null;
        while(headA != null) {
            if(!linkset.contains(headA)) {
                linkset.add(headA);
            }
            headA = headA.next;
        }
        while(headB != null){
            if(linkset.contains(headB)){
                ans = headB;
                return ans;
            }
            headB = headB.next;
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
