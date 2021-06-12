bool isopen(char a){
        if(a=='(' || a=='[' || a=='{' )
            return true;
        return false;
            
    }
    
    bool ispar(string x)
    {
        stack<char> s;
        for(int i=0;i<x.length();i++){
            if(isopen(x[i])){
                s.push(x[i]);
            }
            else{
                if(!s.empty() && !isopen(x[i])){
                    if(x[i]==')' && s.top()=='('){
                        s.pop();
                    }
                    else if(x[i]=='}' && s.top()=='{'){
                        s.pop();
                    }
                    else if(x[i]==']' && s.top()=='['){
                        s.pop();
                    }
                    else return false;
                }
                else
                    return false;
            }
        }
        if(s.empty())
            return true;
        return false;
    }
