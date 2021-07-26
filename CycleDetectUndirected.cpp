#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool dfsUtil(vector<int> adj[],bool visited[],int u,int p){
        
        visited[u]=true;
        for(int i=0;i<adj[u].size();i++)
        {
            if (!visited[adj[u][i]])
        {
           if (dfsUtil(adj, visited, adj[u][i],u))
              return true;
        }
 
        else if (adj[u][i]!=p)
           return true;
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    bool visited[V]={false};
	    bool t=false;
	    for(int i=0;i<V;i++){
	        if(visited[i]==false)
	        t=dfsUtil(adj,visited,i,-1);
	        if(t==true)
	        return t;
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends