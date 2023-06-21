//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  int helper(string s){
        int cnt=1;
        unordered_map<char,int> map;
        for(int i =0; i<s.length(); i++){
            if(map.find(s[i])==map.end()){
                map[s[i]]=cnt;
                cnt*=2;
            }
            else{
                int temp = map[s[i]];
                map[s[i]]=cnt;
                cnt*=2;
                cnt = cnt-temp;
            }
        }
        return cnt;
    }
  public:
    string betterString(string str1, string str2) {
        // code here
        int first = helper(str1);
        int second = helper(str2);
        // cout<<first << " "<<second <<endl;
        if(first >= second){
            return str1;
        }
        else{
            return str2;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends