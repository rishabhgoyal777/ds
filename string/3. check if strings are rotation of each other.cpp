bool func(string a, string b){
  if(a.length() != b.length())
     return false;
  else{
    string concat= a + a;
    if(concat.find(b) != -1)
      return true;
  }
  return false;
}
