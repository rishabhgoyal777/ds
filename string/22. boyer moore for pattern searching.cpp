saurabh school yt
code not sure

vector<int> func(String text, String pattern){

  vector<int> res;
  int n=text.length();
  int m=patten.length();
  int hash[26];

  for(int i=0;i<26;i++)
    hash[i]=m;
  for(int i=0;i<m-2;i++)
    hash[pattern[i]-'a']=m-1-i;
    
  int i=0;
  while(i<=n-m){
    int j=m-1;
    while(j>=0 && text[j+i] == pattern[j])
      j--;
    if(j<0){
      res.push_back(i);
    }
//     else{
      i+=hash[text[i+m-1]-'a'];
//     }
  }
  return vector;
}
      
