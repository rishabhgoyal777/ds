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


    vector<int> heapification(vector<int> &res, int n) {
        int i=n/2 - 1; //last non leaf node index
        for(i;i>=0;i--){
            heapify(res,i,n);
        }
        
        return res;
    }
