//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isvalid(int gap,int k,vector<int> &stalls)
    {
        int cnt=1;
        int prev=stalls[0];
        int n=stalls.size();
        for(int i=1;i<n;i++)
        {
            if(stalls[i]-prev>=gap)
            {
                cnt++;
                prev=stalls[i];
            }
        }
        if(cnt>=k) return true;
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int l=1;
        int h=stalls[n-1]-stalls[0];
        int res;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            
            if(isvalid(mid,k,stalls))
            {
                res=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends