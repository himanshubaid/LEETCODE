//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int n,m;
  void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &vis,int r0,int c0,vector<pair<int,int>> &vec)
  {
      vis[i][j]=1;
      vec.push_back({i-r0,j-c0});
      
      int dr[]={1,-1,0,0};
      int dc[]={0,0,-1,1};
      
      for(int x=0;x<4;x++)
      {
          int row=i+dr[x];
          int col=j+dc[x];
          if(row>=0 && row<n && col>=0 && col<m && !vis[row][col] && grid[row][col]==1)
          {
              dfs(row,col,grid,vis,r0,c0,vec);
          }
      }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>se;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    vector<pair<int,int>>vec;
                    dfs(i,j,grid,vis,i,j,vec);
                    se.insert(vec);
                }
            }
        }
        
        return se.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends