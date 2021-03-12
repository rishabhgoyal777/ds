bool matching(int i, int j, int stlen,int pattlen,string str,string pattern){
  if(i==stlen && j==pattlen)
    return true;

  if(i==stlen){
    for(int k=j;k<pattlen;k++){
      if(pattern[k]!='*')
        return false;
    }
    return true;
  }

  if(j==pattlen)
    return false;

  if(pattern[j]=='?')
    return matching(i+1,j+1,stlen,pattlen,str,pattern);

  if(pattern[j]=='*')
    return matching(i,j+1,stlen,pattlen,str,pattern)||matching(i+1,j,stlen,pattlen,str,pattern);

  if(str[i]!=pattern[j])
    return false;

  return matching(i+1,j+1,stlen,pattlen,str,pattern);
}

int wildCard(string pattern,string str){
  int stlen=str.length();
  int pattlen=pattern.length();

  return matching(0,0,stlen,pattlen,str,pattern);
}
