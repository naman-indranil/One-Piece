public class majorityElementN_2 {
        public int majorityElement(int[] nums) {
            int count = 0, num = 0;
            int n = nums.length;
            for(int i = 0 ;i < n; i++){
                if(count ==0){
                    num = nums[i];
                    count++;
                }else if(num == nums[i]){
                    count++;
                } else if(num != nums[i]){
                    count--;
                }
            }
            return num;
        }
}
