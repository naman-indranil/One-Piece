import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class nonRepeatingSubstring {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int n = s.length();
        int maxLength = 0;
        int[] charIndex = new int[128];
        Arrays.fill(charIndex, -1);
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (charIndex[s.charAt(right)] >= left) {
                left = charIndex[s.charAt(right)] + 1;
            }
            charIndex[s.charAt(right)] = right;
            maxLength = Math.max(maxLength, right - left + 1);
        }
        System.out.println("Max len : "+maxLength);
    }
}
