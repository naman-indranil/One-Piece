import java.util.Scanner;

public class stocks01 {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        n= sc.nextInt();
        int[] ar = new int[n];
        for(int i = 0;i<n;i++){
            ar[i] = sc.nextInt();
        }
        int mini = Integer.MAX_VALUE, maxi = Integer.MIN_VALUE;
        for(int i = 0;i<n;i++){
            mini = Math.min(mini, ar[i]);
            maxi = Math.max(maxi, ar[i]-mini);
        }
        System.out.println("Max profit : "+maxi);
    }
}
