// for sorted LIST



Node * removeDuplicates( Node *head)
{
 Node * p = head;
 Node * q = p->next;
 while(q)
 {
   if( p->data == q->data )
    {
      p->next=q->next;
      q=q->next;
    }
    else {
    p=q;
    q=q->next;}
 }
 return head;
}


// for unsorted linked LIST

Node * removeDuplicates( Node *top)
{
    unordered_set<int> s;

    Node *head = NULL, *tail = NULL;
    head = tail = top;

    s.insert(top->data);
    top = top->next;

    while(top)
    {
    if(s.find(top->data) == s.end()) //find funct returns an iterator to the element
                                  // if found, else returns an iterator pointing
                                      //to the end of unordered_set.
    {
        tail->next = top;
        tail = top;
        s.insert(top->data);
        }

        top = top->next;
    }

    tail->next = NULL;

    return head;
}
