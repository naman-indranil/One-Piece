import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class two2sum {
    
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        int[] id = new int[2];
        Map<Integer,Integer> t = new HashMap<>();
        for(int i=0;i<n;i++){
            t.put(nums[i],i);
        }
        for(int i=0;i<n;i++){
            if(t.get(target-nums[i])!=null && t.get(target-nums[i]) != i){
                id[0]=i;
                id[1] = t.get(target-nums[i]);
                break;
            }
        }
        return id;
    }
}
