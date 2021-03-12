class Solution{
  public:

  void topo(vector<int> graph[], int u, int K, bool vis[], string &s){
    vis[u]=true;

    for(auto x:graph[u]){
      if(!vis[x]){
        topo(graph,x,K,vis,s);
      }
    }
    s.push_back(u+'a');
  }

  string findOrder(string dict[], int N, int K) {
      vector<int> graph[K];
      for(int i=0;i<N-1;i++){  // n string to n-1 pairs. pairs compare kiye 0-1, 1-2, 2-3, and so on
        int min_len=min(dict[i].length(), dict[i+1].length());
        for(int j=0;j<min_len;j++){  // pair mein 0 se leke minimum length wale ki length tak character compare kiye
          if(dict[i][j]!=dict[i+1][j]){
            graph[dict[i][j]-'a'].push_back(dict[i+1][j]-'a'); //agar char same nhi hai. toh arrow from 1st word ke us character to that char of 2nd word. aur -'a' krdiya to store graph in form of 0 1 2 3 ...(i.e. numbers).
            break;
          }
        }
      }
      // baad mei iss graph ka topological sort krdiya
      string s="";
      bool vis[K]={false};
      for(int i=0;i<K;i++){
          if(!vis[i])
      topo(graph,i,K,vis,s);
      }
      reverse(s.begin(),s.end());  // topoSort mein jiska dfs pehle khtm hota wo jaata strring mei. isliye reverse ki end mei
      return s;
  }
};
