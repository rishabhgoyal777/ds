Input: N = 9, C = 4
pages = {5, 0, 1, 3, 2, 4, 1, 0, 5}
Output: 8
  

int pageFaults(int n, int c, int pages[]){
        unordered_set<int> s; //cache memory
        unordered_map<int,int> mp; // storing index of pages
        
        int pf=0; 
        
        for(int i=0;i<n;i++){
            if(s.size() < c){ //if set size less than capacity. 
                if(s.find(pages[i]) == s.end()){ //element not in set
                    pf++; //fault
                    s.insert(pages[i]); //insert in set
                    mp[pages[i]] = i; //store index
                } else{ //update index
                    mp[pages[i]]=i; 
                }
                
            } else{ //else performLRU
                if(s.find(pages[i]) == s.end()){ // not in set and set full. So remove least recently used page. which will be the one with smallest index in map. because we                                                     are traversin array from 0 to n
                    int ele=INT_MAX;
                    int value;
                    for(auto it=s.begin(); it!=s.end(); it++){ //in set *it will be element value. an mp[*it] will be index of element in pages array. find one with least index
                        if(mp[*it] < ele){
                            ele=mp[*it];
                            value=*it;  
                        } 
                    }
                    pf++; 
                    s.erase(value);
                    s.insert(pages[i]);
                    mp[pages[i]] = i;  
                } else{
                    mp[pages[i]]=i;
                }
            }
        }
        return pf;
    }
