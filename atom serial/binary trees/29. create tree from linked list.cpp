// The structure of Link list Node is as follows
// struct Node
// {
//     int data;
//     struct node* next;
//
//     Node(int x){
//         data = x;
//         next = NULL;
//     }
// };
// The structure of TreeNode is as follows
// struct TreeNode
// {
//     int data;
//     TreeNode *left;
//     TreeNode *right;

//     TreeNode(int x){
//     data=x;
//     left=right=NUll;
// }
// };

void convert(Node *head, TreeNode *&root) {
    queue<TreeNode*> q;
    if(!head)
    return;

    root=new TreeNode(head->data);
    q.push(root);
    head=head->next;
    while(head){
        TreeNode* t=q.front();
        q.pop();
        TreeNode* lchild= new TreeNode(head->data);
        head=head->next;
        q.push(lchild);

        TreeNode* rchild=NULL;
        if(head){
            rchild= new TreeNode(head->data);
            head=head->next;
            q.push(rchild);
        }
        t->left=lchild;
        t->right=rchild;

    }
}
