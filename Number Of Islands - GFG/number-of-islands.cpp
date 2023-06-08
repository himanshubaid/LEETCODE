//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
        int findpar(int u,vector<int>&parent)
        {
            if(u==parent[u])
                return u;
            else
                return parent[u]=findpar(parent[u],parent);
        }
        
        void Union(int u,int v,vector<int>&parent,vector<int>&size)
        {
            int pu=findpar(u,parent);
            int pv=findpar(v,parent);
            
            if(pu==pv) return;
            if(size[pu]<size[pv])
            {
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
            else
            {
                parent[pv]=pu;
                size[pu]+=size[pv];
                
            }
        }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        vector<int>parent(m*n);
        for(int i=0;i<m*n;i++)
        {
            parent[i]=i;
        }
        
        vector<int>size(m*n,1);
        vector<int>ans;
        int cnt=0;
        vector<vector<int>>mat(n,vector<int>(m,0));
        for(auto it:operators)
        {
            int row=it[0];
            int col=it[1];
            if(mat[row][col]==1)
            {
                ans.push_back(cnt);
                continue;
            }
            int no=row*m+col;
            mat[row][col]=1;
            cnt++;
            int dr[]={1,-1,0,0};
            int dc[]={0,0,1,-1};
            for(int i=0;i<4;i++)
            {
                int nr=row+dr[i];
                int nc=col+dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]==1)
                {
                    if(findpar(nr*m+nc,parent)!=findpar(no,parent))
                    {
                        cnt--;
                        Union(nr*m+nc,no,parent,size);
                    }
                }
            }
            ans.push_back(cnt);
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends