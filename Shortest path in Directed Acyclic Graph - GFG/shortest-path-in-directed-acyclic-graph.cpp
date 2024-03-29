//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>>adj[N];
        for(int i=0;i<M;i++)
        {    int u=edges[i][0];
             int v=edges[i][1];
             int wt=edges[i][2];
            adj[u].push_back({v,wt});
            
        }
        vector<int>dis(N,1e9);
        dis[0]=0;
        queue<int>q;
        q.push(0);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto it:adj[node])
            {   
                int child=it.first;
                int wt=it.second;
                if(dis[child]>dis[node]+wt)
                {
                    dis[child]=dis[node]+wt;
                    q.push(child);
                }
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if(dis[i]==1e9)
             dis[i]=-1;
        }
        return dis;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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