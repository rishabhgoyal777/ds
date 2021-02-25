node* lca(node* root,int a, int b){
  if(!root)
    return NULL;
  if(root->data==a || root->data==b)
    return root;
  node* l=lca(root->left,a,b);
  node* r=lca(root->right,a,b);
  if( l && r )
    return root;
  if(l)
    return l;
  if(r)
    return r;
  return NULL;

}

1. agar root nhi to return NULL
2. agar kisi root ka data a ya b ke equal to return root kyoiki wohi lca hoga        a                          a
                                                                                    \                       /
                                                                                      b                   b
3. wrna
l= left subtree
r= right subtree
agar dono null nhi matlab dono mei 2. wala chla matlab root is LCA                  c
                                                                                  /   \
                                                                                a       b

4. agar abhi bhi func chal raha matlb dono exist nhi krte
toh agar l not null to return l                                                 c
function call niche jaygei d return kregi (3.) to c pe                        /   \
(4.) wala chlega ki left return kr rha d sirf to return d hoga              d       e
                                                                          /   \
                                                                        a       b
5. agar r not null matlab return r

6.agar abhi bhi chl raha mtlb no LCA found return null
