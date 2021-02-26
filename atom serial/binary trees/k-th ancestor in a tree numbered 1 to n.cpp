tree numbered 1 to n
create an array to store ancestor of every node element
then arr[i] conatins ancestor of i and arr[arr[i]] has ancestor of arr[i] whenever counnt reaches k print that value of i

void generatearr(Node* root, int ancestor[]){
    arr[root->data]=-1;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp->left){
            ancestor[temp->left->data]=temp->data;
            q.push(temp->left);
        }
        if(temp->right){
            ancestor[temp->right->data]=temp->data;
            q.push(temp->right);
        }
    }
}

int kthAncestor(Node *root, int k, int node)
{
    int arr[10000];

    generatearr(root, arr);

    int count=0;
    while(node!=-1){
        node=arr[node];
        count++;
        if(count==k)
            break;
    }
    return node;
}
