#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int hash[26]={0};
        queue<char> q;
        for(int i=0;i<n;i++){
            q.push(a[i]); hash[a[i]-'a']++;

            while(!q.empty()){
                if(hash[q.front()-'a']>1){
                    q.pop();
                }
                else{
                    cout<<q.front()<<" ";
                    break;
                }
            }

            if(q.empty()){
                cout<<-1<<" ";
            }

        }
        cout<<endl;
    }}
