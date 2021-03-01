void bottomView(struct Node *root)
{
    map<int,int> m;
    queue<pair<Node*,int> > q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int> p= q.front();
        q.pop();
        Node* t=p.first;
        int hd= p.second;
        // if(m.find(hd)==m.end())
        m[hd]=t->data;  // in top view we are keeping 1st entry in each block here we are keeping the last entry
        if(t->left)      // block is vertical blocks with horizontal distance 0 at root going -1... and 1... on each sides
            q.push(make_pair(t->left,hd-1));
        if(t->right)
            q.push(make_pair(t->right,hd+1));

    }
    for(auto i: m){
        cout<<i.second<<" ";
    }
}
