#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        vector<int> v;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int k;
        cin>>k;
        for(int i=0;i<n-k+1;i++){ int flag=1;
            for(int j=i;j<i+k;j++){
                if(a[j]<0){
                    v.push_back(a[j]); flag=0; break;
                }
            }if(flag==1) v.push_back(0);
        }

        for(int i : v){
            cout<<i<<" ";
        }cout<<endl;
    }
}

o(nk)

optimized o(n) using dequeue(sliding window problem)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int k;
        cin>>k;
        deque<int> q;
        int i;
        for(i=0;i<k;i++){
            if(a[i]<0)
                q.push_back(i);
        }

        for(i;i<n;i++){
            if(!q.empty())
                cout<<a[q.front()]<<" ";
            else cout<<0<<" ";

            while(!q.empty() && q.front() < (i-k+1)){
                q.pop_front();
            }

            if(a[i]<0)
                q.push_back(i);

        }
         if(!q.empty())
            cout<<a[q.front()]<<" ";
         else cout<<0<<" ";
         cout<<endl;

    }
}
