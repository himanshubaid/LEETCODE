//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int func(int i,int tar,int arr[],int n,vector<vector<int>> &dp)
	{   
	    
	    
	    if(i==0)
	    {
	        if(tar==arr[0] && arr[0]==0) 
	        return 2;
	        if(tar==0 || tar==arr[0])
	        return 1;
	        
	        return 0;
	    }
	    
	    if(dp[i][tar]!=-1) return dp[i][tar];
	    
	    int nottake=func(i-1,tar,arr,n,dp)%1000000007;
	    int take=0;
	    
	    if(arr[i]<=tar) 
	    take=func(i-1,tar-arr[i],arr,n,dp)%1000000007;
	    
	   
	    
	    return dp[i][tar]=(take+nottake)%1000000007;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return func(n-1,sum,arr,n,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends