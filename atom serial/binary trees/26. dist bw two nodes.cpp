find lca and then int dist=dis(root,a) + dis(root,b) - (2*dis(root,lc->data));
or
int dist=dis(lc,a,d) + dis(lc,b,d) ;


Node* lca(Node* root,int a, int b){
  if(!root)
    return NULL;
  if(root->data==a || root->data==b)
    return root;
  Node* l=lca(root->left,a,b);
  Node* r=lca(root->right,a,b);
  if( l && r )
    return root;
  if(l)
    return l;
  if(r)
    return r;
  return NULL;

}
int dis(Node* root, int a,int d){
    if(!root)
        return 0;
    if(root->data==a)
        return d;
    int d1=dis(root->left,a,d+1);                                    | or      int d1;
    if(d1) return d1;                 /# if d1 is other than 0 /#    |     if( (d1=dis(root->left,a,d+1)) || (d1=dis(root->right,a,d+1)) )
    else return dis(root->right,a,d+1);                              |          return d1;
}
yaha pe hai ki pehle left wala chlega agr wo kuch return kre to right wala na chle agar na return kre tabhi chle bas right

int findDist(Node* root, int a, int b) {
    Node* lc=lca(root ,a ,b);
    int d=0;
    int dist=dis(root,a,d) + dis(root,b,d) - (2*dis(root,lc->data,d));  ya pher int dist=dis(lc,a,d) + dis(lc,b,d) ;
    return dist;
}
