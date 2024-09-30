import java.util.PriorityQueue;
import java.util.Arrays;
public class kthLargestElement {
    class Solution {
        public int findKthLargest(int[] nums, int k) {
            PriorityQueue<Integer> pq = new PriorityQueue<Integer>(k+1);
            
            for(int i=0;i<nums.length;i++){
                pq.add(nums[i]);
                if(pq.size()>k){
                    pq.poll();
                }
            }
            
            return pq.peek();
        }
    }
}
