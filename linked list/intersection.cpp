Node* findIntersection(Node* head1, Node* head2)
{
    Node*p=head1;
    Node*q=head2;
    Node*n=new Node(0);
    Node*head=n;
    while(p&&q)
    { if(p->data < q->data)
      p=p->next;
      else if(q->data < p->data)
      q=q->next;
      else if(p->data==q->data)
      { n->next=new Node(p->data); n=n->next; n->next=NULL; p=p->next; q=q->next;  }
    }
    return head->next;
}
