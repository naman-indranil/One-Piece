class Solution {
public:
    int differ(string a,string b){
        int l1=a.length();
        int l2=b.length();
        int i=0,j=0;
        int d=0;
        char x,y;
        for(;i<l1 && j<l2;i++,j++){
            x=a[i];
            y=b[j];
            if(x!=y)
                d++;
        }
        if(i<l1)
            d+=l1-1-i;
        if(j<l2)
            d+=l2-1-j;
        return d;
    }
    int ladderLength(string bw, string ew, vector<string>& wl) {
        int l=wl.size();
        int f=0;
        for(int i=0;i<l;i++){
            if(ew==wl[i])
            {
                f=1;
                break;
            }
        }
        if(f==0)
            return 0;
        if(bw.compare(ew)==0)
            return 0;
        queue<pair<string,int>> q;
        q.push({bw,1});
        bool *visited=new bool[l];
        for(int i=0;i<l;i++)
            visited[i]=false;
        while(!q.empty()){
            pair<string,int> t=q.front();
            q.pop();
            if(t.first.compare(ew)==0)
                return t.second;
            for(int i=0;i<l;i++){
                if(visited[i])
                    continue;
                int d=differ(wl[i],t.first);
                if(d==1)
                {
                    q.push({wl[i],t.second+1});
                    visited[i]=true;
                }
            }
        }
        return 0;
    }
};