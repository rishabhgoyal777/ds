max heap properties =>1. complete binary tree
                      2. every parent greater than left and rigth child/subtree
                      
   if parent at i then 
                left child=2*i+1
                right child=2*i+2



    int sizebt(Node* root){
          if(!root)
            return 0;

        return 1 + sizebt(root->left) + sizebt(root->right);
    }
    
    bool checkheap(Node* root, int n, int index){
        if(!root)
            return 1;
        
        if(index >=n) //for checking complete binary tree or not
            return 0;
            
        if((root->left && root->left->data >= root->data) || (root->right && root->right->data >= root->data) )
           return 0;
           
        return checkheap(root->left, n, 2*index+1) && checkheap(root->right, n, 2*index+2); //third parameter for checikng complete binary tree
    }
    
    bool isHeap(struct Node * root)
    {
        if(!root)
            return 1;
        
        int n = sizebt(root);
        int index=0;
        if(checkheap(root,n,index))
            return 1;
            
        return 0;
    }
