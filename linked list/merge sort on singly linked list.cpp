void partition(Node* head, Node*&a, Node*&b){
    Node* slow=head;
    Node* fast=head;
    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    a=head;
    b=slow->next;
    slow->next=NULL;
}

Node* merge(Node* a, Node* b){
    if(!a)
        return b;
    if(!b)
        return a;
    Node* result=NULL;

    if(a->data < b->data){
        result=a;
        result->next=merge(a->next,b);
    }
    else{
        result=b;
        result->next=merge(a,b->next);
    }
    return result;
}

Node* mergeSort(Node* head) {
    if(!head || !head->next)
        return head;

    Node *a , *b;
    partition(head,a,b);

    a=mergeSort(a);
    b=mergeSort(b);

    return merge(a,b);
}
