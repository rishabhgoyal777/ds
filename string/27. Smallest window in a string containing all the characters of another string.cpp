string smallestWindow (string s, string t)
    {
        int hash[256]={0};
        int start=0;
        int count=0;
        int ans=INT_MAX;
        
        //getting no of diff ele in pattern and hashing ele
        for(int i=0;i<t.length();i++){
            if(hash[t[i]]==0)
                count++;
            hash[t[i]]++;
        }  
        int i=0;
        int j=0;
        
        while(j<=s.length()){
            hash[s[j]]--;
            if(hash[s[j]]==0)
                count--;
                
            if(count==0){
               while(count==0){                
                   if(j-i+1 < ans){
                       ans=j-i+1;
                       start=i;
                   }
                   
                   hash[s[i]]++;
                   if(hash[s[i]]>0)
                    count++;
                   
                   i++;
               } 
            }
            j++;
        }
        
        if(ans==INT_MAX)
            return "-1";
        else
            return s.substr(start,ans);
    }
