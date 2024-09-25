import java.util.ArrayList;
import java.util.List;

public class permutations {
    class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> c = new ArrayList<>();
        solve(nums, res, c);
        return res;
    }
    void solve(int[] nums, List<List<Integer>> res, List<Integer> c){
        if(c.size() == nums.length){
            res.add(new ArrayList<>(c));
            return;
        }
        for(int i = 0;i<nums.length;i++){
            if(!c.contains(nums[i])){
                c.add(nums[i]);
                solve(nums,res,c);
                c.remove(c.size()-1);
            }
        }
    }
}
}
