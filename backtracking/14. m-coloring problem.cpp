bool isSafe(int u, int i, bool graph[101][101],int color[], int V, int m){
  for(int v=0;v<V;v++){
    if(graph[u][v] && color[v]==i)
      return false;
  }
  return true;
}

bool gc(bool graph[101][101], int color[], int m, int V, int u){
  if(u==V) return true;    // agar node V pe phunch gyi hai mtlb sbh colour hogye kyoki 0 to V-1 mei V nodes hogye.

//color loop started from 1 cuz 0 taken as no color
  for(int i=1;i<=m;i++){  // check for every color
    if(isSafe(u,i,graph,color,V,m)){ // if it is safe to color
      color[u]=i;     //colored it

      bool flag=gc(graph,color,m,V,u+1);// now recursing and checking if other nodes can be assigned other colors
      if(flag) return true;  // return true if the current allocation was successful

      color[u]=0;  // if not true, backtrack, and remove the colour for that node
    }
  }
  return false;// if all possibilities are false, and no colour can be assigned, return false
}

bool graphColoring(bool graph[101][101], int m, int V) {
      int color[V]={0};
      return gc(graph,color,m,V,0);
}
