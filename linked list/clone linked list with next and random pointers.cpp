Node* copyList(Node *start){
  if(!start) return start;

	Node* curr = start;
  // created copy of every node bw itself and next node
	while (curr)
	{
		Node* temp = new Node(curr->data);
		temp->next=curr->next;
        curr->next=temp;
        curr=temp->next;
	}

	curr = start;
  // connected arbitray for these copy nodes acc to original list
	while (curr)
	{
		if(curr->arb)
		    curr->next->arb= curr->arb->next;
		else
		    curr->next->arb= NULL;

		curr =curr->next->next;
	}

	Node* head1 = start, *head2 = start->next;

	Node* b = head2;
  Node* a= head1;

  //sepearted both list. even index and odd index
	while (head1 && head2 && head1->next && head2->next )
	{
		head1->next = head1->next->next;

		head2->next =head2->next->next;

		head1 = head1->next;
		head2 = head2->next;
	}
  // finished both list with NULL
  head1->next=NULL;
  head2->next=NULL;

	return b; // returned copy list
}
