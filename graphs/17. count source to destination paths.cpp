Given a directed acyclic graph(DAG) with n nodes labeled from 0 to n-1. Given edges, s and d ,count the number of ways to reach from s to d.There is a directed Edge from vertex edges[i][0] to the vertex edges[i][1].

Example:
Input: edges = {{0,1},{0,3},{1,2},{3,2}},
n = 4, s = 0, d = 2
Output: 2
Explanation: There are two ways to reach at
2 from 0. These are-
1. 0->1->2
2. 0->3->2

class Solution {
public:
void dfs(vector<int>g[], int n, int s, int d, bool vis[], int &count){
  if(s==d){
    count++;
    return;
  }
  vis[s]=true;
  for(auto x:g[s]){
    if(!vis[x]){
      dfs(g,n,x,d,vis,count);
    }
  }
  vis[s]= false;
}

	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    bool vis[n]={false};
      int count=0;
      vector<int> g[n];
      for(auto i:edges){         // creating adjacency list
        g[i[0]].push_back(i[1]);
      }

      dfs(g,n,s,d,vis,count);
      return count;
	}
};
