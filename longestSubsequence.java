import java.util.Arrays;

public class longestSubsequence {
    public int longestConsecutive(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int max = 0 , cur = 0, prev = -1;
        for(int i = 0;i<n; i++){
            if(cur == 0){
                cur++;
                prev = nums[i];
            } else if(prev+1 == nums[i] || prev == nums[i]){
                cur++;
                prev = nums[i];
            } else {
                if(max < cur){
                    max = cur;
                }
                cur = 1;
                prev = nums[i];
            }
            
        }
        if(max<cur) 
        max=cur;
        return max;
    }
}
