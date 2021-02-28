class Solution
{
    public:   
    
    void leaftodll(Node* root, Node* &head, Node* &tail){
       if(!root)
       return;
       leaftodll(root->left,head,tail);
  
       if(!head){
          head=tail=root;
       }
       else{
         root->left=tail;
         tail->right=root;
         tail=root;
       }
  
       leaftodll(root->right,head,tail);
    }

    Node * bToDLL(Node *root)
    {
        Node* head=NULL;
        Node* tail=NULL;
        leaftodll(root,head,tail);
        return head;
    }
};
