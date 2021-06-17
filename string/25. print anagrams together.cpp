vector<vector<string> > Anagrams(vector<string>& v) 
{
    vector<vector<string> > res;
    unordered_map<string, vector<string> > mp;
    
    
    for(int i=0;i<v.size();i++){
        string temp=v[i];
        sort(temp.begin(),temp.end());
        mp[temp].push_back(v[i]);
    }
    
    for(auto it:mp){
        vector<string> vec=it.second;
        res.push_back(vec);
    }
    return res;
}
