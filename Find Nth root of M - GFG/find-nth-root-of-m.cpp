//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int func(int x,int n)
    {
        int ans=1;
        for(int i=0;i<n;i++)
        {
           ans*=x; 
        }
        
        return ans;
    }
	int NthRoot(int n, int x)
	{
	   int l=1;
       int h=x;
       
       while(l<=h)
       {
           int mid=(h+l)/2;
           
           if(pow(mid,n)==x)
           return mid;
           
           if(pow(mid,n)<x)
           l=mid+1;
           else 
           h=mid-1;
           
       }
       return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends