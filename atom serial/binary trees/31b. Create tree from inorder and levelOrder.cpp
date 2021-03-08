Node func(in, lo)
If size0 return null

Node root= new node lo[0]
int index = search(in, root->data)

Vector newin1 for left = copy 0 to index-1 from in
Vevtor newin2 for right =copy index+1 to n from in

Vector newlo1 for left = find(in,lo,0,index-1)
Vector newlo2 for right= find(in,lo,index+1,n)

Root->left=func(newin1, newlo1)
Root->right=func(newin2,newlo2)
Return root


Search func finds root->data in inorder arr
Find func generates new inorder arr for left and right
Side in the order in which elements coming in 
levlorder. Can be done using set.

unordered_set<int> s;

    for (int i=iStart;i<index;i++)
        s.insert(inorder[i]);

    int lLevel[s.size()];  // Left 

    int rLevel[iEnd-iStart-s.size()]; // Right

    int li = 0, ri = 0;

    for (int i=1;i<n;i++) {
        if (s.find(levelOrder[i]) != s.end())
            lLevel[li++] = levelOrder[i]; 
        else
            rLevel[ri++] = levelOrder[i];        
    }

    
