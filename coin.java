// A Naive recursive Java program to find minimum of coins
// to make a given change sum
import java.io.*;
public class coin
{
    // m is size of coins array (number of different coins)
    static int minCoins(int coins[], int m, int sum)
    {
       // base case
       if (sum == 0) return 0;
     
       // Initialize result
       int res = Integer.MAX_VALUE;
     
       // Try every coin that has smaller value than sum
       for (int i=0; i<m; i++)
       {
         if (coins[i] <= sum)
         {
             int sub_res = minCoins(coins, m, sum-coins[i]);
     
             // Check for INT_MAX to avoid overflow and see if
             // result can minimized
             if (sub_res != Integer.MAX_VALUE && sub_res + 1 < res)
                res = sub_res + 1;
         }
       }
       return res;
    }
    public static void main(String args[])
    {
       int coins[] =  {9, 6, 5, 1};
       int m = coins.length;
       int sum = 11;
       System.out.println("Minimum coins required is "+ minCoins(coins, m, sum) );
    }
}/* This code is contributed by Rajat Mishra */
