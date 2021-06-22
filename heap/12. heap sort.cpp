Time complexity of heapify is O(Logn). Time complexity of createAndBuildHeap() is O(n) and the overall time complexity of Heap Sort is O(nLogn).

void heapify(int arr[], int i, int n){
  if(i>=n)
     return;
  
  int parent = i;
  int lchild = 2*i+1; 
  int rchild = 2*i+2;
  
  if(lchild < n && arr[lchild] > arr[parent])
     parent = lchild;
  if(rchild < n && arr[rchild] > arr[parent])
     parent = rchild;
  
  if(parent != i){
    swap(arr[i], arr[parent]);
    heapify(arr,parent,n);
  }
}


void heapsort(int arr[], int n){
  int i=n/2 -1;
  
  //heapify=> maxheap. Arr[0] will be the greatest ele
  for(i;i>=0;i--){
    heapify(arr,i,n);
  }
  
  //sorting
//   starting from last index. swapping greatest ele to last index and heapifying remaining arr of size i or n-1 at index 0. 
  for(i=n-1;i>0;i--){
    swap(arr[i], arr[0]);
    heapify(arr,0,i):
  } 
}
    
