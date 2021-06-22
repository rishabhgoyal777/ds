join both arrays.
  start from last non leaf node and heapify this result array for every non leaf node recursively

void heapify(vector<int> &res, int i, int n){
        if(i>=n)
            return;
        
        int parent= i;
        int lchild= 2*i+1;
        int rchild= 2*i+2;
        
        // parent changed to greatest of parent, lchild, rchild
        if(lchild<n && res[lchild] > res[parent])
            parent = lchild;  
        if(rchild<n && res[rchild] > res[parent])
            parent = rchild;
            
        //if parrent has been changed from parent to lchild or rchild    
        if(parent != i){
            swap(res[parent], res[i]); //swap
            heapify(res,parent,n); //and call recursively for the child with which it has been swapped as parent is pointing to the greatest child
        }
        
        
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> res=a;
        for(auto x:b){
            res.push_back(x);
        }
      
        int i=(n+m)/2 - 1; //last non leaf node index
        for(i;i>=0;i--){
            heapify(res,i,n+m);
        }
        
        return res;
    }
