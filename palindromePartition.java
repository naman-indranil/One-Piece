import java.util.ArrayList;
import java.util.List;

public class palindromePartition {
    class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        List<String> cur = new ArrayList<>();
        String temp = "";
        int l = s.length();
        int i = 0;
        solve(s , res, cur, temp, i , l);
        return res;
    }
    void solve (String s , List<List<String>> res, List<String> cur, String temp, int i , int l){
        if(i==l){
            if(isPalin(cur)){
                res.add(new ArrayList<>(cur));
            }
            return;
        }
        String k = ""+ s.charAt(i);
        cur.add(k);
        solve(s, res, cur, temp, i+1, l);
        cur.remove(cur.size()-1);
        if(cur.size() > 0){
            temp = cur.get(cur.size()-1);
            cur.remove(cur.size()-1);
            temp = temp + s.charAt(i);
            cur.add(temp);
            solve(s, res, cur, temp, i+1, l);
        }
    }

    boolean isPalin(List<String> c){
        for(String t : c){
            String rev = new StringBuilder(t).reverse().toString();
            if(!t.equals(rev))
            return false;
        }
        return true;
    }
}
}
