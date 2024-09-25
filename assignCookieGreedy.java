import java.util.Arrays;

public class assignCookieGreedy {
    class Solution {
    public int findContentChildren(int[] g, int[] s) {
        int res = 0;
        Arrays.sort(g);
        Arrays.sort(s);
        int cl  =g.length;
        int sl  =s.length;
        int j = 0;
        for(int i = 0;i<cl ;i++){
            if(j>=sl)
            break;
            if(g[i] <= s[j]){
                j++;
                res++;
            } else {
                while(j<sl){
                    if(g[i]<=s[j]){
                        res++;
                        j++;
                        break;
                    }
                                        j++;

                }
            }
        }
        return res;
    }
}
}
