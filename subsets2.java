//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        Set<List<Integer>> res = new HashSet<>();
        int l = nums.length;
        List<Integer> s = new ArrayList<>();
        findSubSets(nums,0,l,res,s);
        List<List<Integer>> r = new ArrayList<>();
        res.add(new ArrayList<>());
        return res.stream().collect(Collectors.toList());
        
    }
    void findSubSets(int[] nums, int i , int l , Set<List<Integer>> res, List<Integer> s){
        if(i==l){
            return;
        }
        s.add(nums[i]);
        findSubSets(nums,i+1,l,res,s);
        res.add(new ArrayList<>(s));
        s.remove(s.size()-1);
        findSubSets(nums,i+1,l,res,s);

    }
}