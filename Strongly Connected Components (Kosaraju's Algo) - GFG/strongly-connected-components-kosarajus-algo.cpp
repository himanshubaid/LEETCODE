//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void dfs(int node,vector<vector<int>>& adj,vector<int> &vis,stack<int> &st)
	{
	    vis[node]=1;
	    for(auto it:adj[node])
	    {
	        if(!vis[it])
	        {
	            dfs(it,adj,vis,st);
	        }
	    }
	    st.push(node);
	}
	
	void dfs1(int node,vector<vector<int>>& radj,vector<int> &vis)
	{
	    vis[node]=1;
	    for(int it:radj[node])
	    {
	        if(!vis[it])
	        {
	            dfs1(it,radj,vis);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,st);
            }
        }
        
        vector<vector<int>> radj(V);
        
        for(int i=0;i<V;i++)
        {   vis[i]=0;
            for(auto it:adj[i])
            {
                radj[it].push_back(i);
            }
        }
        int scc=0;
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            if(!vis[node])
            {
                scc++;
                dfs1(node,radj,vis);
                
            }
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends