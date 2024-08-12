public class maxConsecutive1s {
    public int findMaxConsecutiveOnes(int[] nums) {
        int maxOnes = 0;
        int l = nums.length;
        int s = 0;
        for(int i = 0;i<l;i++){
            if(nums[i] == 1){
                s=s+1;
            } else {
                maxOnes = Math.max(maxOnes,s);
                s=0;
            }
        }
        if(s>0 && s > maxOnes){
            maxOnes = s;
        }
        return maxOnes;
    }
}
