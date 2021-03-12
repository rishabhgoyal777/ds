
class Solution{
public:

    void permu(set<string> &ans,string &S,int start,int n){
      if(start==n-1){
        ans.insert(S);
        return;
      }
      permu(ans,S,start+1,n);
      S.insert(start+1," ");
      permu(ans,S,start+2,n+1);
      S.erase(start+1,1);
    }

    vector<string> permutation(string S){
        set<string> ans;  //set is used for controling duplicates and mantaining ascending order
        permu(ans,S,0,S.length());
        vector<string> res;
        for(auto z:ans){
            res.push_back(z);
        }
        return res;
    }
};
