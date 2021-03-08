linked list ka head reference se bheja hai taaki head ko increment kre to puri tree ke liye head increment ho linked list ka.

Node* create(Node* &head, int n){
  if(n==0) return NULL;
  Node* root= new Node();

  root->left=create(head,n/2);

  root->data = head->data;
  head=head->next;

  root->right = create(head,(n-1)/2);

  return root;
}
