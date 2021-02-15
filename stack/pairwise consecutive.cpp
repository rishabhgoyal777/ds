bool pairWiseConsecutive(stack<int> s)
{ int x,y;
    while(!s.empty()){
        x=s.top(); s.pop();
        if(s.empty()) return true;
        y=s.top(); s.pop();

        if(abs(x-y)!=1){
            return false;
        }

    } return true;
}
