bool detectLoop(Node* head)
{struct Node *p= head;
 struct Node *q= head;
    do {
        p=p->next;
        q=q->next;
        if(q)
        q=q->next;
    }
    while(p && q && p!=q );
    if(p==q)
    return 1;
    else return 0;
}

================================================

bool detectLoop(Node* head)
{
    Node* fast = head->next;
    Node* slow = head;

    while( fast != slow )
    {
        if( !fast || !fast->next ) return 0;
        fast=fast->next->next;
        slow=slow->next;
    }
    return 1;
}
