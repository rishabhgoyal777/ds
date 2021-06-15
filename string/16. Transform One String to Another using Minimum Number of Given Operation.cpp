
Given two strings A and B, the task is to convert A to B if possible. The only operation allowed is to put any character from A and insert it at front.
Find if it’s possible to convert the string. If yes, then output minimum no. of operations required for transformation.
  
int func(string a,string b){
  int n1=a.length();
  int n2=b.length();
  if(n1 != n2)
    return -1;
 
  //check if possible
  imt hash[256]={0}; 
  for(int i=0;i<n1;i++)
    hash[a[i]]++;
  for(int i=0;i<n1;i++)
    hash[b[i]]--;
  for(int i=0;i<256;i++)
    if(hash[i] != 0)
      return -1;
  //count operatons => start from end. if same decremnt. if not while not same increase count 
  int res=0;
  int i=n1-1; int j=n1-1;
  while(i>=0 && j>=0){
    if(a[i]==b[j]){
      i--;j--;
    }
    else{
      while(i>=0 && a[i] != b[j]){
        i--;
        res++;
      }
    }
  }
  return res;
}
