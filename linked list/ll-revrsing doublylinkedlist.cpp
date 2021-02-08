Node* reverseDLL(Node * head)
{
   struct Node *p= head;
   struct Node *temp=head;
   while(p)
{  temp=p->next;
   p->next=p->prev;
   p->prev=temp;
   p=p->prev;
if(p!= NULL && p->next==NULL)
head=p;}
return head;}
