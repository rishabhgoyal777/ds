stack<int> deleteMid(stack<int>s,int sizeOfStack,int current)
{
    // check if current is half of the stack size, then you are at mid of stack
    if(current==sizeOfStack/2)
    {
        s.pop();
        return s;
    }

    int x=s.top();
    s.pop();
    current+=1;

    // recursively call deleteMid funciton
    s=deleteMid(s,sizeOfStack,current);

    s.push(x);

    return s;
}
