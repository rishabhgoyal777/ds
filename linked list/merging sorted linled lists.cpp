recursive
======================
Node* merge(Node* root1, Node* root2){
    if(!root1)
        return root2;
    if(!root2)
        return root1;

    Node* result;

    if(root1->data < root2->data){
        result=root1;
        result->next= merge(root1->next, root2);
    }
    else{
        result=root2;
        result->next= merge(root1, root2->next);
    }
    return result;
}

itterative
=================
Node* sortedMerge(Node* head_A, Node* head_B)
{
    Node * p = head_A;
    Node * q = head_B;
    Node * n;      //new_head
    Node * r;

    if(head_A==NULL)
    return head_B;

    if(head_B==NULL)
    return head_A;

    if(p->data < q->data)
    { n=r=p; p=p->next; r->next=NULL;}
    else
    { n=r=q; q=q->next;  r->next=NULL; }

    while(p && q)
    {if(p->data < q->data)
      { r->next=p;
        r=p;
        p=p->next;
        r->next=NULL;
      }
    else
      { r->next=q;
        r=q;
        q=q->next;
        r->next=NULL;
      }
    }
    if(p)
    r->next=p;
    if(q)
    r->next=q;

    return n;
}
