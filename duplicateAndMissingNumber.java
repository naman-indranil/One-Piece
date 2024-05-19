import java.util.Arrays;
import java.util.Scanner;

public class duplicateAndMissingNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        int sum = n*(n+1)/2;
        int ts=0;
        for(int i = 0;i<n;i++){
            nums[i]=sc.nextInt();
            ts= ts+nums[i];
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
        int missing =  num + sum -ts;
        System.out.println("Missing : "+missing+" , duplicate : "+num);



    }

    void alternate(){
        long n = A.length;

        long SN = (n*(n+1))/2;

        long S2N = (n * (n+1) * (2*n+1))/6;

        long S = 0;

        long S2 = 0;

        

        for(int i=0; i<n; i++){

            S+=A[i];

            S2 += (long)A[i] * (long)A[i];

        }

        

        long val1 = S - SN;

        long val2 = S2 - S2N;

        

        val2 = val2 / val1;

        long x = (val1 + val2) / 2;

        long y = x - val1;

        int ans [] = {(int)x, (int)y};
    
    }
}
