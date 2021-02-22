queue<long long int> rev(queue<long long int> q)
{
    stack<int>s;
    while(!q.empty()){
        s.push(q.front()); q.pop();
    }

    while(!s.empty()){
        q.push(s.top()); s.pop();
    }

    return q;
}




using RECURSION

void reverseQueue(queue<long long int>& q)
{
    // Base case
    if (q.empty())
        return;

    // Dequeue current item (from front)
    long long int data = q.front();
    q.pop();

    // Reverse remaining queue
    reverseQueue(q);

    // Enqueue current item (to rear)
    q.push(data);
}
