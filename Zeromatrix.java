import java.util.Scanner;

public class Zeromatrix {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int m,n;
        m = sc.nextInt();
        n = sc.nextInt();
        int[][] mat = new int[m][n];
        int[] row = new int[m];
        int[] col = new int[n];
        for(int i = 0; i<m; i++){
            for(int j=0;j<n;j++){
                mat[i][j] = sc.nextInt();
                if(mat[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for(int i = 0; i<m; i++){
            for(int j=0;j<n;j++){
                if(row[i] == 1) {
                    mat[i][j]=0;
                }
                if(col[j] == 1) {
                    mat[i][j] = 0;
                }
            }
        }
        for(int i = 0; i<m; i++){
            for(int j=0;j<n;j++){
                System.out.print(mat[i][j]+" ");
            }
            System.out.println("");
        }
    }
    
}
