int count(struct node* head, int search_for)    //search_for
{struct node *p = head;
int count=0;
while(p){
if (p->data==search_for)
{count++;}

p=p->next;


} return count ;}
