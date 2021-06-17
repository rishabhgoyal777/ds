string findSubString(string str)
    {
        int count=0; //count of total distinct elements in string
        int counter=0; //count of distinct ele in string window i to j
        int minlen=INT_MAX;
        
        //getting count
        set<char> s;
        for(int i=0;i<str.length();i++){
            s.insert(str[i]);
        }
        count=s.size();
        
        //increasing window to right and when counter = count start squeezing window from left
        unordered_map<char, int> mp;
        int i=0;
        int j=1;
        mp[str[i]]++;
        counter++;
        
        while(i<=j && j<str.length()){
            if(counter<count){
                if(mp[str[j]]==0) counter++;
                mp[str[j]]++;
                j++;
            }
            else{
                minlen=min(minlen,j-i);
                if(mp[str[i]]==1) counter--; 
                mp[str[i]]--;
                i++;
            }
        }
        
        while(counter==count){
            minlen=min(minlen,j-i);
            if(mp[str[i]]==1) counter--;
            mp[str[i]]--;
            i++;
        }
        // cout<<minlen<<endl;
        return str.substr(i-1,minlen);
        
    }
