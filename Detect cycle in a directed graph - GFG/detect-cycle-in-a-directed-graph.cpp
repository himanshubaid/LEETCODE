//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &inrecursion)
    {
        vis[node]=1;
        inrecursion[node]=1;
        
        for(auto &it:adj[node])
        {
            if(!vis[it] && dfs(it,adj,vis,inrecursion))
            return true;
            else if(inrecursion[it])
            {
                return true;
            }
        }
        
        inrecursion[node]=false;
        return false;
    }
    void bfs(int V, vector<int> adj[],int &count)
	{
	    
	    vector<int>indegree(V,0);
	    
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	           
	        }
	        
	    }
	    
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        count++;
	        
	        for(auto it:adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            q.push(it);
	        }
	    }
	    
	    
	}
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int>vis(V,0);
        vector<int>inrecursion(V,0);
        
        /*for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,inrecursion))
                return true;
            }
        }*/
        int count=0;
        bfs(V,adj,count);
        
        if(count==V)
        return false;
        else
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends