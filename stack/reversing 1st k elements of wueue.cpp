queue<ll> modifyQueue(queue<ll> q, int k)
{
    stack<long long> s;
    queue<long long> r;

    for(int i=0;i<k;i++){
        s.push(q.front()) ; q.pop();
    }

    while(!s.empty()) {
        r.push(s.top()); s.pop();
    }


    while(q.size()){
        r.push(q.front()) ; q.pop();

    }

    return r;


}
