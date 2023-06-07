//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DSUnion{
    public:
    vector<int>parent,rank;
    
    DSUnion(int n)
    {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        parent[i]=i;
    }
    
    int findpar(int u)
    {
        if(u==parent[u])
        return u;
        return parent[u]=findpar(parent[u]);
    }
    
    void Union(int u,int v)
    {
        int up=findpar(u);
        int vp=findpar(v);
        
        if(up==vp) return;
        
        if(rank[up]<rank[vp])
           parent[up]=vp;
        else if(rank[vp]<rank[up])
           parent[vp]=up;
        else
           {
               rank[up]++;
               parent[vp]=up;
           }
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
               int node=i;
               int adjnode=it[0];
               int wt=it[1];
               edges.push_back({wt,{node,adjnode}});
            }
            
        }
        sort(edges.begin(),edges.end());
        int sum=0;
        DSUnion ds(V);
        for(auto it:edges)
        {
            int u=it.second.first;
            int v=it.second.second;
            int wt=it.first;
            if(ds.findpar(u)!=ds.findpar(v))
            {
                sum+=wt;
                ds.Union(u,v);
            }
        }
        
        return sum;
    }
};
/*class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>vis(V,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int sum=0;
        pq.push({0,0});
        
        while(!pq.empty())
        {
            auto it=pq.top();
            int wt=it.first;
            int node=it.second;
            pq.pop();
            
            if(vis[node]) continue;
            vis[node]=1;
            sum+=wt;
            for(auto it:adj[node])
            {   int adjnode=it[0];
                int adjdis=it[1];
                if(!vis[adjnode])
                pq.push({adjdis,adjnode});// automatically least dist will be on the top to pop
            }
        }
        return sum;
    }
};*/

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends