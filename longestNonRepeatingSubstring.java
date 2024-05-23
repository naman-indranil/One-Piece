import java.util.Arrays;

public class longestNonRepeatingSubstring {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int maxlen = 0;
        int[] charindex = new int[128];
        Arrays.fill(charindex,-1);
        int left = 0;
        for(int i = 0;i<n;i++){
            if(charindex[s.charAt(i)] >= left){
                left=charindex[s.charAt(i)] + 1;
            }
            charindex[s.charAt(i)] = i;
            maxlen = Math.max(maxlen, i-left +1);
        }
        return maxlen;
    }
}
