public class removeDuplicatesInArray {
    public int removeDuplicates(int[] nums) {
        int p1 = 1 , p2 = 1;
        int curr = nums[0];
        int l = nums.length;
        while(p2<l){
            if(nums[p2]==curr){
                p2++;
            } else {
                nums[p1]=nums[p2];
                p1++;
                curr = nums[p2];
            }
        }
        int k = p1;
        for(;p1<l;p1++){
            nums[p1]=-1;
        }
        return k;
    }
}
