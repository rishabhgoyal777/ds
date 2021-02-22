vector<long long> nextSmallerElement(vector<long long> arr, int n){
  stack<long long int> s;
  vector<long long int> v;
  for(int i=0;i<n;i++){
      if(s.empty()){
          v.push_back(-1);
          s.push(arr[i]);
      }
      else{
          if(arr[i] <= s.top()){
              while(!s.empty() && arr[i] <= s.top()){
                  s.pop();
              }
              if(s.empty())
               v.push_back(-1);
              else
               v.push_back(s.top());

           s.push(arr[i]);
          }
          else{
              v.push_back(s.top());
              s.push(arr[i]);
          }
      }
  }
  return v;
}
