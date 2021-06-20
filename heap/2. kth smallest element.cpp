// arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
          priority_queue<int> hp;
        for(int i=0;i<=r;i++){
            hp.push(arr[i]);
            if(hp.size()>k){
                hp.pop();
            }
        }
        return hp.top();
    }
