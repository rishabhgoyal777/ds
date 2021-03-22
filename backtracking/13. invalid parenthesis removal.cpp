class Solution {
public:
    bool isParenthesis(char a){
        if( a=='(' || a==')' )
            return true;
        return false;
    }

    int minremoval(string s){
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(!isParenthesis(s[i]))
                continue;
            else{
                if(s[i]=='(')
                    st.push(s[i]);
                else{
                    if(st.empty())
                        st.push(s[i]);
                    else if(st.top()==')')
                        st.push(s[i]);
                    else
                        st.pop();
                }
            }
        }
        return st.size();
    }

    bool isvalid(string s){
        int count=0;
        for(int i=0;i<s.length();i++){
            if(!isParenthesis(s[i]))
                continue;
            if(s[i]=='(' )
                count++;
            else if(s[i]==')' )
                count--;
            if(count<0)
                return false;
        }
        return count==0 ;
    }

    void func(string s, set<string> &ans, int removals){
        if(ans.find(s)!=ans.end())
            return;
        if(removals==0){
            if(isvalid(s))
                ans.insert(s);
            return;
        }

        for(int i=0;i<s.length();i++){
            string temp=s.substr(0,i);
            temp.append(s.substr(i+1));
            if(ans.find(temp)!=ans.end())
                continue;
            func(temp,ans,removals-1);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int removals=0;
        removals=minremoval(s);

        set<string> ans;
        func(s,ans,removals);

        vector<string> res;
        for(auto x: ans){
            res.push_back(x);
        }
        return res;
    }
};
