Given an array and a range [lowVal, highVal], partition the array around the range such that array is divided in three parts. 
1) All elements smaller than lowVal come first. 
2) All elements in range lowVal to highVVal come next. 
3) All elements greater than highVVal appear in the end. 
The individual elements of three sets can appear in any order.

void threeWayPartition(vector<int>& arr,int a, int b)
    {
        int low=0;
        int high=arr.size()-1;
        for(int i=0;i<=high;){
            if(arr[i] < a){
                swap(arr[i++],arr[low++]);
            }
            else if(arr[i] > b){
                swap(arr[i],arr[high--]);
            }
            else{
                i++;
            }
        }
    }

Another Method -> similar to sort aray of 0 1 2
===============
void threeWayPartition(vector<int>& arr,int a, int b) {
  int low=0; int mid=0;
  int high= arr.size()-1;
  
  while(mid<=high){
    if(arr[mid]<a){
      swap(arr[mid++],arr[low++]);
    }
    else if(arr[mid] >= a && arr[mid] <= b){
      mid++;
    }
    else{
      swap(arr[mid],arr[high--]);
    }
  }
}
