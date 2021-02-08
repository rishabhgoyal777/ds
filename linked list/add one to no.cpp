void reverse(Node *&h)
{
Node *b=NULL,*c=NULL;
while(h)
{
c=b;
b=h;
h=h->next;
b->next=c;
}
h=b;
}
// o(n^2)  que mei
Node *addOne(Node *head)
{
Node *c,*d;
reverse(head);
c=head;
if(c->data<9)
{
c->data=c->data+1;
}
else
{
c->data=c->data+1;
while(c->next!=NULL)
{
if(c->data==10)
{
c->data=0;
c->next->data=c->next->data+1;
c=c->next;
}
else
{
break;
}
}
}
reverse(head);
return head;
};
