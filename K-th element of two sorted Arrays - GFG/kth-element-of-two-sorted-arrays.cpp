//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        
    }
    int kthElement(int nums1[], int nums2[], int n, int m, int k)
    {
        
        if(n>m)
        return kthElement(nums2,nums1,m,n,k);
        
        int l=max(0,k-m);
        int h=min(k,n);

        while(l<=h)
        {
            int cut1=(l+h)/2;
            int cut2=k-cut1;// for both odd and even

            int l1 = cut1==0 ? INT_MIN : nums1[cut1-1];
            int l2 = cut2==0 ? INT_MIN : nums2[cut2-1];

            int r1=cut1==n?INT_MAX:nums1[cut1];
            int r2=cut2==m?INT_MAX:nums2[cut2];

            if(l1<=r2 && l2<=r1)
            {
                
                return max(l1,l2);
            }
            else if(l1>r2)
            h=cut1-1;
            else
            l=cut1+1;

        }
        return -1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends