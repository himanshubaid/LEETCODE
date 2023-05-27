//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int>hash(n);
        for(int i=0;i<n;i++)
         hash[i]=i;
         
        vector<int>dp(n,1);
        int maxi=0;
        int lastindex;
       for(int i=1;i<n;i++)
       {
          for(int prev=i-1;prev>=0;prev--)
          {  
              if(arr[prev]<arr[i] && dp[i]<=dp[prev]+1 )
              {
                  dp[i]=dp[prev]+1;
                  hash[i]=prev;
                  
              }
              

          }
          
          if(dp[i]>maxi)
          {
              maxi=dp[i];
              lastindex=i;
          }
          
       }
       vector<int>ans;
       ans.push_back(arr[lastindex]);
       while(lastindex!=hash[lastindex])
       {
           lastindex=hash[lastindex];
           ans.push_back(arr[lastindex]);
       }
        
       reverse(ans.begin(),ans.end());
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends