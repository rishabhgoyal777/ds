Given a string S delete the characters which are appearing more than once consecutively. aditya rajiv yt

  
    string removeConsecutiveCharacter(string s)
    {
        if(s.length() < 2)
            return s;
        int j=0;  
        for(int i=1;i<s.length();i++){ //if equal i incremented
            if(s[i]!=s[j]){  //if not equal j incremented and changed with next different element
               j++;
               s[j]=s[i];
            }
        }
        return s.substr(0,j+1);
    }
