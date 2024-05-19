import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class mergeIntervalsMatrix {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int[][] intervals = new int[n][2];
        for(int i = 0;i < n;i++){
            for(int j =0;j<2;j++){
                intervals[i][j]=sc.nextInt();
            }
        }
        int i =0;
        int mi=0;
        Arrays.sort(intervals, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return a[0] - b[0];
            }
        });
        for(;i<n;){
            int t = intervals[i][1];
            while(i<n){
                if(t<intervals[i][0]) {
                    t=Math.max(t,intervals[i-1][1]);
                    break;
                } else {
                    t=Math.max(t,intervals[i][1]);
                }
                i++;
            }
            mi++;
        }
        int[][] merged = new int[mi][2];
         i =0;
         mi=0;
        for(;i<n;){
            int t = intervals[i][1];
            merged[mi][0] = intervals[i][0];
            while(i<n){
                if(t<intervals[i][0]) {
                    t=Math.max(t,intervals[i-1][1]);
                    break;
                } else {
                    t=Math.max(t,intervals[i][1]);
                }
                i++;
            }
            merged[mi][1] = t;
            mi++;
        }
        for(int k=0;k<mi;k++){
            System.out.println("");

            for(int j=0;j<2;j++){
                System.out.print(merged[k][j]+",");

            }
        }
    }
}
