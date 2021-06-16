string secFrequent (string arr[], int n)
    {
        unordered_map<string, int> mp;
        
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        int firstmx=INT_MIN; int secondmx=INT_MIN;
        for(auto it = mp.begin();it !=mp.end();it++){
            if(it->second > firstmx){
                secondmx=firstmx;
                firstmx=it->second;
            }
            else{
                if(it->second > secondmx && it->second != firstmx){
                    secondmx=it->second;
                }
            }
        }
      
        for(auto it = mp.begin();it !=mp.end();it++){
            if(it->second ==secondmx)
                return it->first;
        }
    }
