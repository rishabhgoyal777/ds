Node* merge(Node* a, Node* b){
    if(!a)
        return b;
    if(!b)
        return a;
    Node *result;
    if(a->data < b->data){
        result=a;
        result->next=merge(a->next,b);
        result->next->prev=result;
        // result->prev=NULL;
    }
    else{
        result=b;
        result->next=merge(a,b->next);
        result->next->prev=result;
        // result->prev=NULL;
    }
    return result;
}

void partition(Node* head, Node* &a, Node* &b){
    Node* slow=head, *fast=head;
    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    a=head;
    b=slow->next;
    slow->next=NULL;
    b->prev=NULL;
}

struct Node *sortDoubly(struct Node *head)
{
	if(!head || !head->next)
	   return head;

	Node*a, *b;
	partition(head,a,b);

	a=sortDoubly(a);
	b=sortDoubly(b);

	return merge(a,b);
}
