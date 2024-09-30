import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class kFrequentElements {
    class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int n: nums){
            map.put(n, map.getOrDefault(n,0)+1);
        }
           
        PriorityQueue<Map.Entry<Integer, Integer>> maxHeap = 
                         new PriorityQueue<>((a,b)->(b.getValue()-a.getValue()));
        for(Map.Entry<Integer,Integer> entry: map.entrySet()){
            maxHeap.add(entry);
        }
        int[] res = new int[k];
        int l=0;
        while(l<k){
            Map.Entry<Integer, Integer> entry = maxHeap.poll();
            res[l]=entry.getKey();
            l++;
        }
        return res;
    }
}
}
