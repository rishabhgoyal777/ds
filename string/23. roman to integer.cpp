int romanToDecimal(string &str) {
    unordered_map<char,int> mp;
    
    mp['I']= 1;
    mp['V']= 5;
    mp['X']= 10;
    mp['L']= 50;
    mp['C']= 100;
    mp['D']= 500;
    mp['M']= 1000;
    
    if(str.length()==1)
        return mp[str[0]];
        
    int ans=0;
    int i;
    for(i=0;i<str.length()-1;i++){
        if(mp[str[i]]>= mp[str[i+1]])
            ans+=mp[str[i]];
        else{
            ans+=mp[str[i+1]] - mp[str[i]];  // subtract notation ex=> IV, IX
            i++; //since two charcters are done.
        }
    }
    ans+=mp[str[i]];
    
    return ans;
}
