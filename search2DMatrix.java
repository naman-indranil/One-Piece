public class search2DMatrix {
    public boolean searchMatrix(int[][] matrix, int target) {
        int vl, vr,  vm,flag=0;
        int m = matrix.length;
        int n = matrix[0].length;
        vl=0;
        vr=m-1;
        vm=(vl+1+vr)/2;
        int last = 0;
        while(vl < vr && vl<m && vr<m){
            if(matrix[vm][0] == target){
                break;
            }
            if(matrix[vm][0]<target){
                vl=vm+1;
                last=vm;
            } else if (matrix[vm][0]>target){
                vr = vm-1;
                
            } 
            vm =(vl+1+vr)/2;
        }
        if(vm >= m){
            vm=m-1;
        }
        for(int i=0;i<n;i++){
            if(matrix[vm][i]==target || matrix[last][i]==target){
                flag = 1;
                break;
            }
        }
        if(flag ==1)
        return true;
        return false;
    }
}
