struct node*update(struct node*start,int w)
{ struct node *p= start ;
struct node *q= NULL ;
struct node *last = start;
while (last->next)
last = last->next;
for(int i=0;i<w;i++)
{q=p;
 p = p->next;
}
last->next=start;
start->prev=last;
q->next=NULL;
p->prev=NULL;
start=p;
return start;

}
