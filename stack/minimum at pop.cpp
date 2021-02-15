stack<int> _push(int arr[],int n)
{
   stack<int> s;


   s.push(arr[0]);
   for(int i=1;i<n;i++){
       if(s.top()>arr[i])
          s.push(arr[i]);
       else s.push(s.top());
       }  return s;
}

/* print minimum element of the stack each time
   after popping
*/
void _getMinAtPop(stack<int>s)
{   while(!s.empty()){
    cout<<s.top()<<" "; s.pop();
}}
