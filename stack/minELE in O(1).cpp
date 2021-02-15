int _stack :: getMin()
{
   if(s.empty())
     return -1;
   else
     return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
  int a,y;
  if(s.empty())
  return -1;
  else
  { if(s.top() > minEle)
       {a= s.top(); s.pop();
       return a;}
    else
    {  a=s.top();
       s.pop();
       y=minEle;
       minEle=2*minEle - a;}
    return y;
  }
}

/*push element x into the stack*/
void _stack::push(int x)
{
  if(s.empty())
  {s.push(x); minEle=x;}
  else
    {if(x>=minEle)
        s.push(x);
     else
     { s.push(2*x - minEle); minEle=x;}
    }
}
