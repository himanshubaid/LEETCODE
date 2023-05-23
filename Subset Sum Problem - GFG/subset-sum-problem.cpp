//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool func(int i,int tar,vector<int>arr,vector<vector<int>> &dp)
    {   
        if(tar<0) return 0;
       
        if(dp[i][tar]!=-1) return dp[i][tar];
        
        if(i==0)
        {   if(tar==0) return 1;
        
            if(tar-arr[0]==0) 
             return 1;
             
             return 0;
        }
        
        
        if(func(i-1,tar-arr[i],arr,dp)||func(i-1,tar,arr,dp))
        return dp[i][tar]=1;
        return dp[i][tar]=0;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<int>>dp(arr.size(),vector<int>(sum+1,-1));
        return func(arr.size()-1,sum,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends