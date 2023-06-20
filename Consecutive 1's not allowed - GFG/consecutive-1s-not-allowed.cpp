//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    
	    int oneend=1;
	    int zeroend=1;
	    int sum=oneend+zeroend;
	    int mod=1e9+7;
	    int i=2;
	    while(i<=n)
	    {
	        oneend=zeroend%mod;
	        zeroend=sum%mod;
	        sum=(oneend+zeroend)%mod;
	        i++;
	    }
	    return sum;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends