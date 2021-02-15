Node* reverseDLL(Node * head)
{
    Node* p= head;
    Node* temp=NULL;
    Node* q;
    while(p){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;

       if(p && !p->next)
        q=p;
   }
    return q;
}
