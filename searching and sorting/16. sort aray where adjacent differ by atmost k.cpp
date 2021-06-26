int search(int arr[], int n, int x, int k){
  int i=0;
  while(i<n){
    if(arr[i]==x)
       return i;
    //if element not equal
    int diff=abs(arr[i]-x); //find diff bw current element and required element
    i+= max(1,diff/k); // skip diff/k index. and if required element is in k range from current element diff/k wil be 0. so move max of 1 and diff/k.
  }
  return -1;
}
    
