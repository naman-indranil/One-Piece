class Solution {
    public int search(int[] n, int t) {
        int x=  findPivot(n);
        System.out.print("x = "+x);
        int l , h , m;
        if((t < n[0] && x == 0) || (t>n[n.length-1] && x==0)) {
            return -1;
        } else {
            if(x>0){
                if(t<n[0]){
                    l=x;
                    h=n.length-1;
                } else {
                    l=0;
                    h=x;
                }
            } else {
                l=0;
                h=n.length-1;
            }
        }
        while(l<=h){
            m=l+(h-l)/2;
            if(n[m]<t){
                l=m+1;
            } else if(n[m]>t){
                h=m-1;
            } else {
                return m;
            }
        }
        return -1;
    }
    int findPivot(int[] n){
        int h = n.length-1;
        int l = 1;
        int m = l + (h-l)/2; 
        if(n.length == 2){
            if(n[0]>n[1])
            return 1;
        }
        while(l<=h){
            m=l + (h-l)/2;

            if(m!=0){
                if(n[m-1] > n[m]){
                    return m;
                } else {
                    if(n[0] > n[m]) {
                        h=m-1;
                    } else {
                        l=m+1;
                    }
                }
            } else {
                break;
            }
        }
        return 0;
    }
}