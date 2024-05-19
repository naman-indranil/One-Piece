import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class four4sum {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<>();
        int n = nums.length;
        Arrays.sort(nums);
        Set<String> st = new HashSet<>();
        Map<Long,Integer> map = new HashMap<>();
        for(int i =0;i<n;i++){
            map.put((long)nums[i],i);
        }
        int c=0;
        for(int i =0;i<n;i++){
            Long t1 = (long)nums[i];
            for(int j=i+1;j<n;j++){
                Long t2 = (long) nums[j];
                for(int k=j+1;k<n;k++){
                    Long t=(long)target -t1 -t2 -(long)nums[k];
                    if(map.get(t) != null && map.get(t) > k){
                        List<Integer> r = new ArrayList<>();
                        r.add(nums[i]);
                        r.add(nums[j]);
                        r.add(nums[k]);
                        r.add(target - nums[i] - nums[j] - nums[k]);
                        String s = nums[i]+","+nums[j]+","+nums[k]+","+t;
                        if(!st.contains(s))
                       { res.add(r); st.add(s);}
                        
                    }
                }
            }
        }
        return res;
    }
}
