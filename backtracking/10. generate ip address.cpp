bool isvalidUtil(int i, int j, string &s){

  int len=j-i+1;
  if(len>3)
  return false;
  if(s[i]=='0'){
    if(len==1)
      return true;
    return false;
  }
  int num = stoi(s.substr(i,j-i+1));
  if(num>=0 && num<=255) return true;
  return false;
}

bool isvalid(int i, int j, int k, string &s){
  if( isvalidUtil(0,i,s) && isvalidUtil(i+1,j,s) && isvalidUtil(j+1,k,s) && isvalidUtil(k+1,s.length()-1,s) )
    return true;
  else false;
}

void strpush(int i, int j, int k, string s, string &curr, int n){
  curr.append(s.substr(0,i+1));
  curr.push_back('.');
  curr.append(s.substr(i+1,j-i));
  curr.push_back('.');
  curr.append(s.substr(j+1,k-j));
  curr.push_back('.');
  curr.append(s.substr(k+1,n-k-1));
}

vector<string> genIp(string &s) {
    vector<string> ans;
    int n=s.length();
    for(int i=0;i<n-3;i++){
      for(int j=i+1;j<n-2;j++){
        for(int k=j+1;k<n-1;k++){
          if(isvalid(i,j,k,s)){
            string curr="";
            strpush(i,j,k,s,curr,n);
            ans.push_back(curr);
          }
        }
      }
    }
    return ans;
}
