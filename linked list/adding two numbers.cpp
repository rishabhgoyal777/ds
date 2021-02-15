
Node* reverse(Node* head, int &count){
    Node* p;
    Node*q;
    Node*r;
    p=head; q=r=NULL;
    while(p){
        r=q; q=p; p=p->next;
        q->next=r; count++;
    }
    return q;
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{   if(!first) return second;
    if(!second) return first;

    int count1=0, count2=0;
    Node* fno=reverse(first,count1);
    Node* sno=reverse(second,count2);

    Node*a;
    Node*b;
    Node*z;
    if(count1>count2){
        a=b=fno; z=sno;
    }
    else{
        z=fno; a=b=sno;
    }

    while(a&&z){
        a->data=a->data+z->data;
        if(a->data >=10 && a->next){
            a->data%=10; a->next->data++;
        }
        else if(a->data >=10 && !a->next){
            a->data%=10; a->next = new Node(1);
        }
        a=a->next; z=z->next;
    }

    while(a && a->data >=10){
        if(a->data >=10 && a->next){
            a->data%=10; a->next->data++;
        }
        else if(a->data >=10 && !a->next){
            a->data%=10; a->next = new Node(1);
        }
        a=a->next;
    }
    return reverse(b,count1);

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
