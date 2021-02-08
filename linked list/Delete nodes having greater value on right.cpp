Node *compute(Node *head)
{
  Node *p = head;
  Node *q = NULL;
  Node *r = NULL;


  while(p)
  { r=q; q=p; p=p->next; q->next=r;}
  head=q;
  int max=q->data;
  p=head->next;
 while(p)
 {if(p->data < max)
  {q->next=p->next; p=p->next;
  }
  else {max=p->data; p=p->next; q=q->next;  } }
 return head;
    }
