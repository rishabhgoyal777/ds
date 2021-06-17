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
                if(mp[str[j]]==0) counter++; //new ele found
                mp[str[j]]++;
                j++;
            }
            else if(counter==count){
                if(j-i < minlen){ //if this window s=is min substr
                    minlen=j-i;
                    index=i;  //stroing starting index
                }
                if(mp[str[i]]==1) counter--; //if item being removed is present only once decrease counter
                mp[str[i]]--;
                i++;
            }
        }
        
        while(counter==count){
            if(j-i < minlen){
                minlen=j-i;
                index=i;
            }
            if(mp[str[i]]==1) counter--;
            mp[str[i]]--;
            i++;
        }
        return str.substr(index,minlen);
        
    }
