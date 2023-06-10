//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int func(int x,int n)
    {
        long long int ans=1;
        for(int i=0;i<n;i++)
        {
           ans*=x; 
        }
        
        return ans;
    }
    long long int floorSqrt(long long int x) 
    {
       long long int l=1;
       long long int h=x;
       
       while(l<=h)
       {
           long long int mid=l+(h-l)/2;
           
           long long int no=func(mid,2);
           if(no==x) return mid;
           if(no<x)
           l=mid+1;
           else 
           h=mid-1;
           
       }
       return l-1;
       
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends