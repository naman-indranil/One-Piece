//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {
            String str[] = read.readLine().trim().split(" ");
            int n = Integer.parseInt(str[0]);

            int arr[] = new int[n];
            int dep[] = new int[n];

            str = read.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(str[i]);
            str = read.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) dep[i] = Integer.parseInt(str[i]);

            System.out.println(new Solution().findPlatform(arr, dep));
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    public int findPlatform(int arr[], int dep[]) {
        // add your code here
        int n = arr.length;
        train[] ts = new train[n];
        for(int i = 0;i < n ; i++){
            ts[i] = new train(arr[i], dep[i]);
        }
        Arrays.sort(ts, new Comparator<train>(){
            @Override
            public int compare(train x, train y){
                if(x.a > y.a)
                return 1;
                else if(x.a == y.a)
                {
                  return (x.d - y.d);
                }
                else 
                return -1;
            }
        });
        for(int i = 0;i < n ; i++){
        //   System.out.println(i+ " : "+ts[i].a + " , "+ts[i].d);
        }
        int platforms = 0;
        List<Integer> depts = new ArrayList<>();
        for(int i = 0;i < n ; i++){
            if(depts.size() == 0){
                platforms+=1;
                depts.add(ts[i].d);
            } else {
                int j = 0;
                int f = 0;
                while(j<depts.size()){
                    if(depts.get(j)<ts[i].a){
                        depts.set(j,ts[i].d);
                        f=1;
                        break;
                    }
                    j++;
                }
                if(f==0){
                    platforms+=1;
                depts.add(ts[i].d);
                }
            }
        }
        return platforms;
    }
    class train {
        int a;
        int d;
        train(int a , int d){
            this.a = a;
            this.d = d;
        }
    }
}
