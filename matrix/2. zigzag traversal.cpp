vector<int> printZigZag(int row, int col, int a[][col]){
  int r=0;
  vector<int> v;
  while(r<row){
      for(int i=0;i<col;i++){
        if(r%2==0){
          v.push_back(a[r][i]);
        } else{
          v.push_back(a[r][col-i-1]);
        }
      }
    r++;
  }
}
        
  
