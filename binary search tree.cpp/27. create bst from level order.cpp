pehla elemnt root hi hoga uske bad smaller ko left vector me dal diya
bado ko right vector mei daal diya
phir recursion se is left ka first root hoga and so on.....

Node* create(vector<int> v){
  if(v.size()==0)  return NULL;
  Node* root=new Node(v[0]);
  vector<int> l;
  vector<int> r;
  for(int j=1;j<v.size();j++){
    if(v[j]<v[0])
    l.push_back(v[j]);
    else r.push_back(v[j])
  }
  root->left=create(l);
  root->right=create(r);

  return root;
}
