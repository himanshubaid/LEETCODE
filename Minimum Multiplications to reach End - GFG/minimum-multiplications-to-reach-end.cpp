//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int mod=1e5;
        
        queue<pair<int,int>>q;
        q.push({0,start});
        
        vector<int>dis(1e5,INT_MAX);
        
        while(!q.empty())
        {
           auto it=q.front();
           int dist=it.first;
           int node=it.second;
            q.pop();
               
             for(int i=0;i<arr.size();i++)
              {
                   int no=(int)(node*arr[i])%mod;
                   if(dis[no]>dist+1)
                   {  dis[no]=dist+1;
                      q.push({dist+1,no}); 
                   }
                   
              }
            
        }
        if(dis[end]!=INT_MAX)
        return dis[end];
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends