Reverse the infix expression i.e A+B*C will become C*B+A. Note while reversing each ‘(‘ will become ‘)’ and each ‘)’ becomes ‘(‘.
Obtain the postfix expression of the modified expression i.e CB*A+.
Reverse the postfix expression. Hence in our example prefix is +A*BC.

                                                                                                                               
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

    string infixToPrefix(string e){
        stack<char> s;
        reverse(e.begin(), e.end());
        for(int i=;i<e.length();i++){
          if(e[i]=='(')
            e[i]=')' ;
          else if(e[i]==')')
            e[i]='(' ;
        }
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
        reverse(postfix.begin(), postfix.end());
        return postfix;
    }
};
