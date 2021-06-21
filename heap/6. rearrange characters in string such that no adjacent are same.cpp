// another method in string folder

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> hash;
        for(char a:s){
            hash[a]++;
        }
        
        priority_queue< pair<int, char> > q;
        for(auto i: hash){
            q.push({i.second, i.first});
        }
        
        string ans="";
        
      //top wale ko temp pop krke ans mei add kiya
        auto temp=q.top();
        q.pop();
        ans+=temp.second;
        temp.first--;
        
        while(!q.empty()){
          //top mei nye wala top le liya  
          auto top = q.top();
            q.pop();
            ans+= top.second;
            top.first--;
            // agar temp wala ki freq 1 minus ke bad bhi hai to usko waps push kr diya
            if(temp.first > 0){
                q.push({temp.first, temp.second});    
            }
            //is top ko temp mei dal diya taki nye top ko top mei le ske and so on
            temp=top;
        }
      //case if not possible to make sucj string
        if(ans.size() != s.size())
            return "";
        
        return ans;
        
    }
};
