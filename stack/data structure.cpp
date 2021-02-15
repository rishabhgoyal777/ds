#include<bits/stdc++.h>
using namespace std;
class Stack
{public:
  int size;
  int top;
  int *s;
  Stack() { size=10; top=-1; s=new int[size]; }
  Stack(int a) { size=a; top=-1; s=new int[a]; }
 bool push(int x);
 int pop();
 int peek();
 bool isempty();
 bool isfull();
};
bool Stack::push(int x)
{ if(top >= size-1)
    {cout<<"full"; return false; }
  else
    {s[++top]=x; cout<<x<<"pushed in"; return true; }
}
int Stack::pop()
{
  if(top==-1)
    {cout<<"empty"; return 0;}
  else
    {return s[top--];}
}

int Stack::peek()
{
  if(top==-1)
    {cout<<"empty"; return 0;}
  else
    {return s[top];}
}

bool Stack::isempty()
{
  if(top==-1)
    {cout<<"empty"; return true;}
  else return false;
}

bool Stack::isfull()
{
  if(top >= size-1)
      {cout<<"full"; return true; }
  else
  return false;
}

int main()
{Stack st1;
st1.push(12);
st1.push(19);
}







https://www.geeksforgeeks.org/stack-data-structure/

  List of functions of Stack:

  stack::top() in C++ STL
  stack::empty() and stack::size() in C++ STL
  stack::push() and stack::pop() in C++ STL
  stack::swap() in C++ STL
  stack::emplace() in C++ STL

  Design and Implement Special Stack Data Structure | Added Space Optimized Version
  Implement two stacks in an array
