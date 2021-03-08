reverse inorder traversal kiya aur end wali ka next null kr diya aur usko agle ke liye next bna diya.

void populate(node* p, node* &n){
  if(p){
    populate(p->right,n);

    p->next=n;
    n=p;

    populate(p->left,n);
  }
}

void populateNext(struct node* p)
{
  node* n=NULL;
  populate(p,n);
}
