//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        set<pair<int,int>>se;
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>dis(n+1,1e9);
        vector<int>parent(n+1);
        
        for(int i=1;i<=n;i++)
        parent[i]=i;
        
        
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        se.insert({0,1});
        dis[1]=0;
        while(!se.empty())
        {
            auto it=*se.begin();
            int node=it.second;
            int dist=it.first;
            se.erase({dist,node});
            
            
            for(auto p:adj[node])
            {
                int adjnode=p.first;
                int wt=p.second;
                if(dis[adjnode]>dist+wt)
                {
                    if(dis[adjnode]!=1e9)
                    se.erase({dis[adjnode],adjnode});
                    
                    dis[adjnode]=dist+wt;
                    se.insert({dis[adjnode],adjnode});
                    parent[adjnode]=node;
                    
                }
            }
            
        }
        if(dis[n]==1e9) return {-1};
        
        vector<int>ans;
        int node=n;
        ans.push_back(node);
        
        while(node!=1)
        {   node=parent[node];
            ans.push_back(node);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends