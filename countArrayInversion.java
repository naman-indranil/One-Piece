import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class countArrayInversion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] ar = new int[n];
        int[] nums = new int[n];
        for(int i=0;i<n;i++){
            ar[i] = sc.nextInt();
            nums[i]=ar[i];
        }
        Arrays.sort(nums);
        int count = 0;
        Map<Integer,Integer> indexAr = new HashMap<>();
        for(int i=0;i<n;i++){
            indexAr.put(i,nums[i]);
        }
        for(int i=0;i<n;i++){
            if(ar[i] != indexAr.get(i)) {
                count++;
            }
        }
        System.out.println("Count : "+count);
    }
}
//https://takeuforward.org/data-structure/count-inversions-in-an-array/
