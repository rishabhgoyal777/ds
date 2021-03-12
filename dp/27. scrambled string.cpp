class Solution {
public:
  unordered_map<string, bool> mp;

  bool asd(string s1, string s2){
  if(s1.compare(s2)==0)
    return true;
  if(s1.length() <=1)
    return false;
  if(s2.length() <=1)
    return false;

  string t=s1;
  t.push_back(' ');
  t.append(s2);
  if(mp.find(t) != mp.end())
      return mp[t];

  int n=s1.length();
  bool flag=false;

  for (int i = 1; i < n; i++) {
     if(asd(s1.substr(0,i), s2.substr(0,i)) && asd(s1.substr(i,n-i), s2.substr(i,n-i))
       || (asd(s1.substr(0,i), s2.substr(n-i,i)) && asd(s1.substr(i,n-i), s2.substr(0,n-i)))){

       flag=true;
       break;
     }
  }
  return mp[t]=flag;
}


bool isScramble(string s1, string s2) {
    if(s1.length() != s2.length())
        return false;
    if(s1.compare(s2)==0)
      return true;


    return asd(s1,s2);
   }
};
