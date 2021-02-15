Node * reverse(Node* head){
    Node* p,*q,*r;
    p=head;
    q=r=NULL;
    while(p){
        r=q; q=p; p=p->next;
        q->next=r;
    }
    return q;
}

Node *compute(Node *head)
{
    Node* newh=reverse(head);
    Node* a=newh;
    while(a&&a->next){
        if(a->next->data < a->data){
            a->next=a->next->next;
        }
        else{
            a=a->next;
        }
    }
    Node* ans=reverse(newh);
    return ans;
}
