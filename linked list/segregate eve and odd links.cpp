class Solution{
public:
    Node* divide(int N, Node *head){
        Node* oddstart=NULL;
        Node* evenstart=NULL;
        Node* even=NULL;
        Node* odd=NULL;
        Node* p=head;

        while(p){
            if(p->data%2==0){
                if(!evenstart){
                    evenstart=p; even=p;
                }
                else{
                    even->next=p; even=even->next;
                }
            }
            else{
                if(!oddstart){
                    oddstart=p; odd=p;
                }
                else{
                    odd->next=p; odd=odd->next;
                }
            }
            p=p->next;
        }

        if(!evenstart)
            return oddstart;
        if(!oddstart)
            return evenstart;

        odd->next=NULL;
        even->next=oddstart;

        return evenstart;
    }
};
