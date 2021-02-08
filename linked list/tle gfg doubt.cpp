void reverse(Node *h)
{
Node *a=h,*b=NULL,*c=NULL;
while(a)
{
c=b;
b=a;
a=a->next;
b->next=c;
}
h=q;
}
// o(n^2)  que mei o(N)

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
