class Solution {
public:
    vector<int> dfs(int node,int parent,vector<vector<int>> &adj,string &labels,vector<int>&res)
    {   
        vector<int>count(26,0);
        int label=labels[node]-'a';
        count[label]=1;

        for(int child:adj[node])
        {
            if(child == parent)
                continue;
            
              vector<int>childcount(26,0);
                childcount=dfs(child,node,adj,labels,res);
               for(int i = 0; i<26; i++)
                {
                count[i] += childcount[i];
                }
            
        }
        res[node]=count[label];
        return count;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
    {
        
        vector<vector<int>>adj(n);

        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
         
        
         vector<int>res(n,0);
        dfs(0,-1,adj,labels,res);
        return res;
    }
};