//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isvalid(int barrier,int arr[],int M,int n)
    {
        int stu=1;
        int pages=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>barrier) return false;
            if(pages+arr[i]>barrier)
            {
                stu+=1;
                pages=arr[i];
            }
            else
            {
                pages+=arr[i];
            }
            
        }
        if(stu>M)
        return false;
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M>N) return -1;
       int l=0;
       
       int s=0;
       for(int i=0;i<N;i++)
       {
           s+=A[i];
       }
       int h=s;
       
       int ans=-1;
       while(l<=h)
       {
           int mid=l+(h-l)/2;
           
           if(isvalid(mid,A,M,N))
           {   ans=mid;
              h=mid-1; 
           }
           else
           {
               l=mid+1;
           }
             
        }
        return l;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends