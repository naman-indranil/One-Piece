public class singleElementInSortedArray {
    class Solution {
        public int singleNonDuplicate(int[] nums) {
            int h = nums.length-1;
            int l = 0;
            int mid;
            while(l<h){
                mid = (l + h)/2;
                if(((mid)%2 == 0 && nums[mid] == nums[mid+1]) || (mid %2 == 1 && nums[mid] == nums[mid - 1])){
                    l=mid+1;
                } else 
                h=mid;
            }
            return nums[l];
        }
    }
}
