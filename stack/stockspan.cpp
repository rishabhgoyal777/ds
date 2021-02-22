vector<int> nextLargerElement(int arr[], int n){
   stack<int> s;
   vector<int> v;
   for(int i=0;i<n;i++){
       if(s.empty()){
           v.push_back(-1);
           s.push(i);
       }
       else{
           if(arr[i] >= arr[s.top()]){
               while(!s.empty() && arr[i] >= arr[s.top()]){
                   s.pop();
               }
               if(s.empty())
                v.push_back(-1);
               else
                v.push_back(s.top());
            s.push(i);
           }
           else{
               v.push_back(s.top());
               s.push(i);
           }
       }
   }
   return v;
}


vector <int> calculateSpan(int price[], int n){
    vector<int> v;
    v=nextLargerElement(price,n);
    for(int i=0;i<v.size();i++){
        v[i]=i-v[i];
    }
    return v;
}
