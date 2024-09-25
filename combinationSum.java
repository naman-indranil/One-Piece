import java.util.HashSet;

class Solution {
    public List<List<Integer>> combinationSum(int[] cd, int t) {
        Set<List<Integer>> r = new HashSet<>();
        int curr = 0;
        Arrays.sort(cd);
        List<Integer> l = new ArrayList<>();
        int len = cd.length;
        solve(cd , r, 0, l, t, len);
        return r.stream().collect(Collectors.toList());
    }
    void solve(int[] cd , Set<List<Integer>> r, int i , List<Integer> l, int t, int len){
        if(t == 0){
            r.add(new ArrayList<>(l));
            return;
        } else if(t < 0){
            return;
        }
        if(i == len){
            return;
        }
        l.add(cd[i]);
        solve(cd,r,i,l,t-cd[i],len);
        solve(cd,r,i+1,l,t-cd[i],len);
        l.remove(l.size()-1);
        solve(cd,r,i+1,l,t,len);
    }
}