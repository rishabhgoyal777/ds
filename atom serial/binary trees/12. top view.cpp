void topView(struct Node *root)
{
    map<int,int> m;
    queue<pair<Node*,int> > q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int> p= q.front();
        q.pop();
        Node* t=p.first;
        int hd= p.second;
        if(m.find(hd)==m.end())
            m[hd]=t->data;
        if(t->left)
            q.push(make_pair(t->left,hd-1));
        if(t->right)
            q.push(make_pair(t->right,hd+1));

    }
    for(auto i: m){
        cout<<i.second<<" ";
    }
}
