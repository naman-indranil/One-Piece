public class trappingRainwater {
    public int trap(int[] height) {
        int[] maxl = new int[height.length];
        int[] maxr = new int[height.length];
        int l = height.length;
        int max1=Integer.MIN_VALUE;
        for(int i=0;i<l;i++){
            if(i==0)
            maxl[i]=height[i];
            else
            maxl[i]=max1;
            if(height[i]>max1){
                max1=height[i];
            }
        }
        max1=Integer.MIN_VALUE;
        for(int i=l-1;i>=0;i--){
            if(i== l-1)
            maxr[i]=height[i];
            else
            maxr[i]=max1;
            if(height[i]>max1){
                max1=height[i];
            }
        }
        for(int i=0;i<l;i++){
            System.out.println(i+" : "+maxl[i]+" , "+maxr[i]);
        }
        int area = 0;
        for(int i=0;i<l;i++){
            if(Math.min(maxl[i],maxr[i]) > height[i])
            area = area+(Math.min(maxl[i],maxr[i])-height[i]);
        }
        return area;
    }
}
