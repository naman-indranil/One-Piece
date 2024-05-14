import java.util.Scanner;

public class maximumSumKadane {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] ar = new int[n];
        int currSum = 0 , max = Integer.MIN_VALUE;
        for(int i = 0; i < n; i++) {
            ar[i]= sc.nextInt();
        }
        for(int i = 0;i<n; i++) { 
            currSum = currSum + ar[i];
            if(currSum > max) {
                max = currSum;
            } 
            if (currSum < 0) {
                currSum = 0;
            }
        }
        System.out.println("Sum : "+max);
    }
}
