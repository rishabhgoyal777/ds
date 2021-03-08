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

