import java.util.Arrays;
import java.util.Scanner;

public class duplicateNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i =0;i<n;i++){
            nums[i]= sc.nextInt();
        }
        int num;
        Arrays.sort(nums);
        num=nums[0];
        for(int i =1;i<n;i++){
            if(num == nums[i]) {
                break;
            }
            else {
                num = nums[i];
            }
        }
        System.out.println("Num : "+num);
    }
}
