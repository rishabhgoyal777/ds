bool areIsomorphic(string s1, string s2)
    {
        if(s1.length() != s2.length())
            return false;
        bool visited[256]={0};
        int map[256];
        memset(map, -1, sizeof(map));
        for(int i=0;i<s1.length();i++){
            if(map[s1[i]]==-1){
                
                if(visited[s2[i]])
                    return false;
                    
                map[s1[i]]=s2[i];
                visited[s2[i]]=1;
            }
            else if(map[s1[i]]!=s2[i])
                return false;
        }
        return true;
    }
