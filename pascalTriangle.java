import java.util.ArrayList;
import java.util.*;
public class pascalTriangle {
    public static void main(String[] args) {
        List<List<Integer>> pascalTriangle = new ArrayList<>();
        int numRows;
        Scanner sc = new Scanner(System.in);
        numRows = sc.nextInt();

        for(int i = 0; i<numRows; i++) {
            List<Integer> row = new ArrayList<>();
            if(i==0){
                row.add(1);
            } else {
                row.add(1);
                for(int j=1; j< (pascalTriangle.get(i-1)).size(); j++){
                    row.add(pascalTriangle.get(i-1).get(j-1) + pascalTriangle.get(i-1).get(j));
                }
                row.add(1);
            }
            pascalTriangle.add(row);
        }
        for(int i = 0; i< pascalTriangle.size();i++){
            System.out.println("");
            for(int j=0;j< pascalTriangle.get(i).size();j++){
                System.out.print(pascalTriangle.get(i).get(j)+" ");
            }
        }
    }
}
