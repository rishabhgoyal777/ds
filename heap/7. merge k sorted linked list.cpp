struct compare {
        bool operator()(struct Node* a, struct Node* b){
            return a->data > b->data;
        }
    };
    
Node* mergeKLists(Node *arr[], int k){

    priority_queue<Node*, vector<Node*>, compare > minhp;

    Node* head=new Node(0);//dummy head node
    Node* tail=head;
  
//pushing first node from every linked list
    for(int i=0;i<k;i++){
        minhp.push(arr[i]);
    }

  //for next elemnts moving tail pointer
    while(!minhp.empty()){
        Node* temp = minhp.top();
        minhp.pop();
        tail->next=temp;
        tail=tail->next;
        if(temp->next){
            minhp.push(temp->next);
        }
    }
    return head->next;

}
