DLL-Approach
==============


q-based approach
================
class Solution {
	public:
		string FirstNonRepeating(string a){
		    queue<char> q;
        string res="";
		    int hash[26]={0};

		    for(int i=0;a[i];i++){
		        q.push(a[i]);
		        hash[a[i]-'a']++;

            while(!q.empty()){
              if(hash[q.front()-'a'] > 1){
                q.pop();
              }
              else{
                res.push_back(q.front());
                break;
              }
            }
            if(q.empty())
                res.push_back('#');
		    }
		    return res;
		}
};
