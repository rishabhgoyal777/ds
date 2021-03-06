class Solution
{
    public:
    bool isoperand(char a){
        if(a=='+'|| a=='-'|| a=='*'|| a=='/'|| a=='^'|| a=='(')
            return 0;
        return 1;
    }

    int outpre(char a){
        if(a=='+' || a=='-')
            return 1;
        else if(a=='*' || a=='/')
            return 3;
        else if(a=='^')
            return 6;
        else if(a=='(')
            return 10;
    }

    int inpre(char a){
        if(a=='+' || a=='-')
            return 2;
        else if(a=='*' || a=='/')
            return 4;
        else if(a=='^')
            return 5;
        else
            return 0;
    }

    string infixToPostfix(string e){
        stack<char> s;
        string postfix="";
        for(int i=0;i<e.length();i++){
            if(e[i]==')' ){
                while(s.top()!='('){
                    postfix=postfix+s.top();
                    s.pop();
                }s.pop();
            }
            else if(isoperand(e[i])){
                postfix+=e[i];
            }
            else{
                if(s.empty() || outpre(e[i]) > inpre(s.top())){
                    s.push(e[i]);
                }
                else{
                    while(!s.empty() && outpre(e[i]) <= inpre(s.top())){
                        postfix+=s.top();
                        s.pop();
                    } s.push(e[i]);
                }
            }
        }
        while(!s.empty()){
            postfix+=s.top();
            s.pop();
        }
        return postfix;
    }
};
