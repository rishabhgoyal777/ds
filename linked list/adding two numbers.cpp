struct Node* addTwoLists(struct Node* first, struct Node* second)
{ Node *p = first;
  Node *q = NULL;
  Node *r = NULL;
  int count1=0;
  int count2=0;
  while(p)
  {r=q; q=p; p=p->next; q->next=r; count1++;}
  first=q;

  Node *a = second;
  Node *b = NULL;
  Node *c = NULL;

  while(a)
  {c=b; b=a; a=a->next; b->next=c; count2++;}
  second=b;

  if(count1>count2)
    {a=b=first; p=second; }
  else
    {p=first; a=b=second;}

  while(a&&p)
  { a->data=a->data + p->data;

    if(a->data >= 10 && a->next)
      {a->data=a->data  % 10; a->next->data++; }

    else if(a->data >= 10 && a->next==NULL)
      {a->data=a->data  % 10; a->next = new Node(1);  }

    a=a->next; p=p->next;}

    while(a && a->data >=10)
    {if(a->next)
      {a->data=a->data  % 10; a->next->data++; }
     else
      {a->data=a->data  % 10; a->next = new Node(1);  }
    a=a->next;
    }

    p=b;
    q=NULL; r=NULL;
    while(p)
    {r=q; q=p; p=p->next; q->next=r; count1++;}


return q;
  }

// Node* addSameSize(Node* head1, Node* head2, int* carry)
// {
// Node*temp;
// int car=0;
// if (head1==NULL||head2==NULL)
// return NULL;
// temp=addSameSize(head1->next,head2->next,carry);
// car=(head1->data)+(head2->data)+(*carry);
// head2->data=(car)%10;
// *carry=(car)/10;
// return head2;
//
// // Your code here
// }
// void addCarryToRemaining(Node* head1, Node* curr, int* carry, Node** result)
// {
// // Your code here
// if(head1==curr)
// return;
// int car;
// addCarryToRemaining(head1->next,curr,carry,result);
// if(head1->next==curr)
// {
// head1->next=*result;
// }
// car=(head1->data+*carry);
// head1->data=car%10;
// *(carry)=(car)/10;
// *result=head1;
// }
//
