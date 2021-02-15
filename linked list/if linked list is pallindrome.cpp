DIVIDE LIST IN 2 HALFS REVERSE THE SECOND HALF AND COMPARE EACH DATA

Node* reverse(Node* head){
    Node* a=head;
    Node* b=NULL;
    Node* c=NULL;
    while(a){
        c=b; b=a; a=a->next;
        b->next=c;
    }
    return b;
}

bool isPalindrome(Node *head)
{
    Node*p = head;
    Node*q = head;
    while(q->next && q->next->next){
        p=p->next;
        q=q->next->next;
    }

    Node* r=p->next;
    p->next=NULL;

    Node* head2=reverse(r);

    while(head && head2){
        if(head->data != head2->data)
            return false;
        else{
            head=head->next;
            head2=head2->next;
        }
    }
    return true;
}
