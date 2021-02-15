iterative4
=============

struct Node* reverseList(struct Node *head)
{
    Node* p=head;
    Node* q=NULL;
    Node* r=NULL;

    while(p){
        r=q; q=p; p=p->next;
        q->next=r;
    }
    return q;
}


recursive
===========

struct Node* reverseList(struct Node *head)
{
    if(!head || !head->next)
        return head;

    Node* newh= reverseList(head->next);
    Node* last= head->next;
    last->next= head;
    head->next= NULL;

    return newh;
}
