Use the Hare Tortoise algorithm to find out if there is a loop.
A piece of code is run repeatedly in the Hare Tortoise algorithm, such that, with each execution, the Hare pointer moves 2 nodes ahead and the tortoise pointer moves one node ahead in the linked list. If the two meet, it means there is a loop in the list and the meeting node lies inside the loop.void removeLoop(Node* head)
Next, find the size of the loop.
Make one pointer stay at the meeting point of Hare Tortoise and use the other pointer to complete one round around the loop. Count the steps required to cover the loop.
Let s be the size of the loop.
Now we need 2 pointers again. The first pointer points at the head. Second pointer should be s nodes ahead.
Moves both pointers ahead step by step at same rate. This time the meeting point will be the junction node.

{
    Node* p=head;
    Node* q=head;
    do{
        q=q->next;
        p=p->next;
        if(q)
        q=q->next;
    }while(p&&q&&p!=q);

    if(p==q){        // p and q meet inside loop somewhere
        int count=1;
        q=q->next;
        while(p!=q){                //count nodes in loop
            q=q->next;
            count++;
        }
        p=q=head;

        while(count){        //one pointer at head and one at count nodes ahead
            p=p->next;
            count--;
        }
        while(p!=q){       //move both simultaneously theyll meet at looping point
            p=p->next;
            q=q->next;
        }
        while(q->next!=p){
            q=q->next;
        }
        q->next=NULL;
    }

}
