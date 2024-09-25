//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class Job {
    int id, profit, deadline;
    Job(int x, int y, int z){
        this.id = x;
        this.deadline = y;
        this.profit = z; 
    }
}

class GfG {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        //testcases
		int t = Integer.parseInt(br.readLine().trim());
		while(t-->0){
            String inputLine[] = br.readLine().trim().split(" ");
            
            //size of array
            int n = Integer.parseInt(inputLine[0]);
            Job[] arr = new Job[n];
            inputLine = br.readLine().trim().split(" ");
            
            //adding id, deadline, profit
            for(int i=0, k=0; i<n; i++){
                arr[i] = new Job(Integer.parseInt(inputLine[k++]), Integer.parseInt(inputLine[k++]), Integer.parseInt(inputLine[k++]));
            }
            
            Solution ob = new Solution();
            
            //function call
            int[] res = ob.JobScheduling(arr, n);
            System.out.println (res[0] + " " + res[1]);
        }
    }
}
// } Driver Code Ends


class Solution
{
    //Function to find the maximum profit and the number of jobs done.
    int[] JobScheduling(Job arr[], int n)
    {
        // Your code here
        Arrays.sort(arr, new Comparator<Job>(){
            @Override
            public int compare(Job a, Job b){
                if(a.profit < b.profit){
                    return 1;
                } else if(a.profit == b.profit){
                    return a.deadline - b.deadline;
                } else {
                    return -1;
                }
            }
        });
        for(int i = 0; i < arr.length; i++){
            // System.out.println(i+ " : "+arr[i].deadline + " : "+arr[i].profit);
        }
        int[] res = new int[2];
        int jobCount = 0;
        int[] usedDeadlines = new int[arr.length+1];
        int netProfit = 0;
        for(int i = 0; i < arr.length; i++){
            if(usedDeadlines[arr[i].deadline] != 1){
               jobCount++;
               netProfit = netProfit + arr[i].profit;
               usedDeadlines[arr[i].deadline] = 1;
            } else {
                int j = arr[i].deadline;
                while(j>=1){
                        if(usedDeadlines[j] != 1){
                           jobCount++;
                           netProfit = netProfit + arr[i].profit;
                           usedDeadlines[j] = 1;
                           break;
                        }
                        j--;
                }
            }
        }
        res[0] = jobCount;
        res[1] = netProfit;
        return res;
    }
}

/*
class Job {
    int id, profit, deadline;
    Job(int x, int y, int z){
        this.id = x;
        this.deadline = y;
        this.profit = z; 
    }
}
*/