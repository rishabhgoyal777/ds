bool isSafe(int m[MAX][MAX],int n,int row,int column){
    if(row<0 || row>=n || column<0 || column>=n || m[row][column]==0)
      return false;
    return true;
}

void ratmaze(int m[MAX][MAX],int n,int row,int column,string &path,set<string> &all){
  if(row==n-1 && column==n-1){
    all.insert(path);
    return;
  }
  int row_step[]={-1,1,0,0};
  int col_step[]={0,0,-1,1};
  int dir[]={'U','D','L','R'};

  for(int i=0;i<4;i++){
    if(isSafe(m,n,row+row_step[i],column+col_step[i])){
      m[row][column]=0;
      path.push_back(dir[i]);
      ratmaze(m,n,row+row_step[i],column+col_step[i],path,all);
      m[row][column]=1;
      path.pop_back();
    }
  }
}

vector<string> findPath(int m[MAX][MAX], int n){
    vector<string> res;
    if(m[0][0]==0 || m[n-1][n-1]==0)
    return res;
    string path;
    set<string> all;
    ratmaze(m,n,0,0,path,all);
    for(auto x: all){
      res.push_back(x);
    }
    return res;
}
