//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());

        while (t-- > 0) {
            String inputLine[] = br.readLine().trim().split(" ");
            int n = Integer.parseInt(inputLine[0]);

            int start[] = new int[n];
            int end[] = new int[n];

            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) start[i] = Integer.parseInt(inputLine[i]);

            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) end[i] = Integer.parseInt(inputLine[i]);

            int ans = new Solution().maxMeetings(n, start, end);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends

class pair {
    int first, second;

    public pair(int start, int finish) {
        this.first = start;
        this.second = finish;
    }
}
class Solution {
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    public int maxMeetings(int n, int start[], int end[]) {
        // add your code here
        int max = Integer.MIN_VALUE;
        int res = 0;
        int last = -1;
        pair[] meet = new pair[n];
        for(int i =0;i<n;i++){
            meet[i]=new pair(start[i],end[i]);
        }
        Arrays.sort(meet, new Comparator<pair>() {
            @Override
            public int compare(pair s1, pair s2) {
                return s1.second - s2.second;
            }
        });
        for(int i = 0;i < n ;i++){
             if (meet[i].first > last) {
                res++;
                last = meet[i].second;
            }
        }
        return res;
    }
}
