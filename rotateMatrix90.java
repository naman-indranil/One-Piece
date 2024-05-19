import java.util.Scanner;

public class rotateMatrix90 {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        n= sc.nextInt();
        int[][] matrix = new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = sc.nextInt();
            }
        }
        System.out.println("");
        int temp;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for(int i=0;i<n;i++){
            System.out.println("");

            for(int j=n-1;j>=0;j--){
                System.out.print(matrix[i][j]+",");

            }
        }
    }
}
