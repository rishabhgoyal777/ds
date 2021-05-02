Given an array of pairs of numbers of size N. In every pair, the first number is always smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c. The chain of pairs can be formed in this fashion. The task is to find the length of the longest chain which can be formed from a given set of pairs.

Examples:
Input: N = 5, arr={{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} }
Output: 3
The longest chain that can be formed is of length 3, and the chain is {{5, 24}, {27, 40}, {50, 90}}.

Input : N = 2, arr={{5, 10}, {1, 11}}
Output :1

O(n^2)
====================================
int maxChainLen(struct val p[],int n)
{
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++){
        v.push_back({p[i].first,p[i].second});
    }
    sort(v.begin(),v.end());

    int t[n];
    for(int i=0;i<n;i++){
        t[i]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[j].second < v[i].first)
                t[i]=max(t[i], t[j]+1);
        }
    }

    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,t[i]);
    }
    return ans;
}


O(nlogn) greedy
===============================
bool comp(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

int maxChainLen(struct val p[],int n)
{
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++){
        v.push_back({p[i].first,p[i].second});
    }
    sort(v.begin(),v.end(),comp);
    int i=0;
    int j=1;
    int c=1;
    while(j<v.size()){
        if(v[i].second<v[j].first){
            i=j;j++;c++;
        }
        else{
            j++;
        }
    }
    return c;
}
