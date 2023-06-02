//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:

    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end()), visitedAtaLevel;
        queue<vector<string>> q;
        q.push({beginWord});
        vector<vector<string>> ans;
        int f = 0;
        
        while(q.size()) {
            int n = q.size();
            while(n--) {
                vector<string> path = q.front(); q.pop();
                string word = path.back();
                if(word == endWord) f = 1, ans.push_back(path);

                for(int i=0; i<word.size(); i++) {
                    string org = word;
                    for(char c='a'; c<='z'; c++) {
                        word[i] = c;
                        path.push_back(word);
                        if(s.find(word) != s.end()) q.push(path), visitedAtaLevel.insert(word);
                        path.pop_back();
                    }
                    word = org;
                }
            }
            if(f) break;
            for(string adj : visitedAtaLevel) s.erase(adj);
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends