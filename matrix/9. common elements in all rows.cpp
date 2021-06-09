Time Compexity => O(n*m)
  ============================

vector<int> printCommonElements(int mat[n][m]){
  
  unordered_map<int, int> mp;
  for(int j=0;j<m;j++){ //storing first row
    mp[mat[0][j]]=1; 
  }
  
  for(int i=1;i<n;i++){
    for(int j=0;j<m;j++){
      if(mp[mat[i][j]]==i)  //dulpicate in row will not be taken since it will be greater than i after the first occurence
        mp[mat[i][j]]++;
        
        if(i==n-1 && mp[mat[i][j]]==n) //if it is last row.
          v.push_back(mat[i][j]);
    }
  }
  return v;
}
