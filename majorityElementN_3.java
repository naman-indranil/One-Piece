import java.util.ArrayList;
import java.util.List;

public class majorityElementN_3 {
    class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int c1 =0, c2=0, n1=0,n2=0;
        int n = nums.length;
        int max =(n/3);
        for(int i =0;i<n;i++){
            if(n1 == nums[i]){
                c1++;
            } else if (n2 == nums[i]){
                c2++;
            } else if(c1 == 0){
                n1= nums[i];
                c1++;
            } else if(c2==0){
                n2= nums[i];
                c2++;
            } else {
                c1--;
                c2--;
            } 
        }
        List<Integer> ans=new ArrayList<>();
        if(c1 >0) {
            c1=0;
            for(int i=0;i<n;i++){
                if(n1==nums[i]){
                    c1++;
                }
            }
            if(max < c1){
                ans.add(n1);
            }
        }
        if(c2 >0) {
            c2=0;
            for(int i=0;i<n;i++){
                if(n2==nums[i]){
                    c2++;
                }
            }
            if(max < c2){
                ans.add(n2);
            }
        }
        return ans;
    }
}
}
