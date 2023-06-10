//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int smallerthanequalto(int tar,vector<vector<int>> &matrix)
    {
        int cnt=0;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            int l=0;
            int h=m-1;
            while(l<=h)
            {
                int mid=(l+h)/2;
                if(matrix[i][mid]<=tar)
                l=mid+1;
                else
                h=mid-1;
            }
            cnt+=l;
        }
        return cnt;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        int l=1;
        int h=2000;
        
        while(l<=h)
        {
            int mid=(l+h)/2;
            
            int cnt=smallerthanequalto(mid,matrix);
            if(cnt<=(R*C)/2)
            l=mid+1;
            else
            h=mid-1;
        }
        return l;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends