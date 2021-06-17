void func(string arr[R][C], string ans, int r){
  if(r==R){
    cout<<ans<<endl;
    return;
  }
  
  for(int i=0;i<C;i++){
    if( arr[r][i] != ''){
      func(arr,ans+" "+arr[r][i], r+1);
    }
  }
}
