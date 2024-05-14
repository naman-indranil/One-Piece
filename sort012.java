import java.util.Scanner;

public class sort012 {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int[] ar = new int[n];
        int c0 = 0 , c1 = 0;
        for(int i = 0;i<n;i++){
            ar[i] = sc.nextInt();
            if(ar[i] == 0){
                c0++;
            }
            if(ar[i]==1){
                c1++;
            }
        }

        for(int i=0; i<n; i++) {
            if(c0 > 0){
                ar[i] = 0;
                c0--;
            }
            else if (c1 > 0){
                ar[i] = 1;
                c1--;
            } else {
                ar[i] =2;
            }
        }
        System.out.println("");
        for(int i = 0;i<n;i++){
            System.out.print(ar[i]+" ");
        }
    }
}
