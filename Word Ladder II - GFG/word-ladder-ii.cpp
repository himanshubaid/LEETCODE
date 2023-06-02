//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:

    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>se;
        for(auto &word:wordList)
        {
            se.insert(word);
        }
        
        vector<vector<string>>ans;
        unordered_map<string,int>vis;
        queue<vector<string>>q;
        q.push({beginWord});
        

        int level=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                vector<string> vec=q.front();
                q.pop();

                string word=vec.back();
                if(word==endWord)
                {
                    ans.push_back(vec);
                }

               for(int i=0;i<word.size();i++)
               {
                  for(int c='a';c<='z';c++)
                 {
                    string temp=word;
                    temp[i]=c;
                    if(se.count(temp)>0 )
                    {   vis[temp]=1;
                       vec.push_back(temp);
                       q.push(vec);
                       vec.pop_back();
                    }
                 }
                }
                
            }
            //remove all the visited word
            for(auto it:vis)
             se.erase(it.first);
            vis.clear();
            level++;
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