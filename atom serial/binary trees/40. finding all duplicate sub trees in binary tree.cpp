string printAllDupsUtil(Node* root,unordered_map<string, int> &m, int &flag, vector<int> &v){
    if(!root)
        return "";
    string str="(";
    str+=printAllDupsUtil(root->left,m,flag,v);
    str+=to_string(root->data);
    str+=printAllDupsUtil(root->right,m,flag,v);
    str+=")";
    if(m[str]==1){
    v.push_back(root->data); flag=1;
    }
    m[str]++;
    return str;
}
void printAllDups(Node* root)
{
    unordered_map<string, int> m;
    int flag=0;
    vector<int> v;
    printAllDupsUtil(root,m,flag,v);
    if(flag==0)
    cout<<-1;
    else{
        sort(v.begin(),v.end());
        for(i:v)
        cout<<i<<" ";
    }
}
