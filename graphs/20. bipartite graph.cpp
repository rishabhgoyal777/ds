A Bipartite Graph is a graph whose vertices can be divided into two independent sets, U and V such that every edge (u, v) either connects a vertex from U to V or a vertex from V to U. In other words, for every edge (u, v), either u belongs to U and v to V, or u belongs to V and v to U. We can also say that there is no edge that connects vertices of same set.

A bipartite graph is possible if the graph coloring is possible using two colors such that vertices in a set are colored with the same color. Note that it is possible to color a cycle graph with even cycle using two colors. For example, see the following graph.

It is not possible to color a cycle graph with odd cycle using two colors.


class Solution {
public:
  bool check(int V, vector<int>adj[],int color[],int currColor,int start){
    color[start]=currColor;       //jis node pe hai usko currColor krdiya pher neighbours dekhe

    for(auto x:adj[start]){
      if(color[x]==-1){                 // agar neighbour not colored hai to dekha ki neighbour kya ans de rha. agr false de raha
        bool flag=check(V,adj,color,1-currColor,x);  // to ans hi false
        if(!flag) return false;
      }
      else if(color[x]==color[start])  // ya agr neighbour ka color same as start then also false
          return false;
    }
    return true;                        // if comes out of loop then true
  }

  bool isBipartite(int V, vector<int>adj[]){
    int color[V];
    for(int i=0;i<V;i++)
      color[i]=-1;
    bool flag;
    for(int i=0;i<V;i++){
      if(color[i]==-1)
      flag=check(V,adj,color,0,i);  // do color leliye as currColor 0 and 1 alternate calls mei
      if(!flag) return false;     //agar kisi bhi component ka false aaya to not barpite.
    }
    return true;
	}
};
