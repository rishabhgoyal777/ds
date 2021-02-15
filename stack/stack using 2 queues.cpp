void QueueStack :: push(int x)
{       queue<int> q;
        q1.push(x);
        int y;
        while(!q2.empty()){
            y= q2.front();
            q2.pop();
            q1.push(y);
        }
        q=q1;
        q1=q2;
        q2=q;

}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
       if(q2.empty())
        return -1;

       int y=q2.front();
       q2.pop();
       return y;
}
