//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int precedence(char ch)
    {
        if(ch=='^')
        return 3;
        else if(ch=='*'||ch=='/')
        return 2;
        else if(ch=='+'|| ch=='-')
        return 1;
        else
        return 0;
    }
    string infixToPostfix(string s) 
    {
        stack<char>st;
        string res="";
        for(int i=0;i<s.size();i++)
        {
            if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='B')|| (s[i]>='0'&& s[i]<='9'))
              {
                  res+=s[i];
              }
              else if(s[i]=='(')
              st.push(s[i]);
              else if( s[i]==')')
              {
                  while(st.top()!='(')
                  {
                      res+=st.top();
                      st.pop();
                  }
                  st.pop();
              }
              else{
                  while(!st.empty() && precedence(s[i])<=precedence(st.top()))
                  {
                      res+=st.top();
                      st.pop();
                  }
                  st.push(s[i]);
              }
        }
        
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        return res;
        
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends