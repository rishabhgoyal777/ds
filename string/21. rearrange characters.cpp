Given a string S with repeated characters. The task is to rearrange characters in a string such that no two adjacent characters are the same. 
  
 string rearrangeString(string str)
    {   int n=str.length();
        int hash[26]={0}; //hashing characters in string
        int mx=INT_MIN; //highest frequency
        char t;  //character with highest frequancy
     
        string res(n,' '); //resultant string of size n. intialise with any character.
     
     //finding mx and character t
        for(int i=0;i<n;i++){
            hash[str[i]-'a']++;
            if(hash[str[i]-'a'] > mx){
                mx=max(mx,hash[str[i]-'a']);
                t=str[i];
            }
        }
     
     //if this then not posssible to rearrange
        if(mx > (n+1)/2)
            return "-1";
            
        int index=0;
       
     //starting with highest freq char at even positions, starting at 0 index 
        while(mx>0){
            res[index]=t;
            index+=2;
            mx--;
        }
        
     //set its freq to 0 in hashtable 
        hash[t-'a']=0;
        
     //from that index onwards start adding other characters at alternating positions
        for(int i=0;i<26;i++){
            while(hash[i] > 0){
                index = (index>=n) ? 1 : index;
                res[index]='a'+ i;
                index+=2;
                hash[i]--;
            }
        }
        
        return res;
    }
