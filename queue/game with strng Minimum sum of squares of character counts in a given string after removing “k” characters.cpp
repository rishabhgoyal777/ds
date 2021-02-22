#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int k;
    string s;
    cin>>s;
    cin>>k;
    int a[26]={0};
    for(int i=0;i<s.length();i++){
      a[s[i]-'a']++;
    }

   sort(a,a+26,greater<int>());
   int i=0;
   while(k!=0){
    a[i]--;                             //abbbccc  agar k=2 hai to ek b ek c nikal ne se minimum aayega Sum
    k--;                                // naaki do c ya do b nikal ne se;
    sort(a,a+26,greater<int>());       // isliye bar bar sort krna pdega 1 1 minus krke
   }
      int sum=0;
    for(int i=0;i<26;i++){
      sum+=a[i]*a[i];
    } cout<<sum<<endl;
  }
}

better solution use priority queues they will store in descending order

#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

// Main Function to calculate min sum of
// squares of characters after k removals
int minStringValue(string str, int k)
{
    int l = str.length(); // find length of string

    // if K is greater than length of string
    // so reduced string will become 0
    if (k >= l)
        return 0;

    // Else find Frequency of each character and
    // store in an array
    int frequency[MAX_CHAR] = {0};
    for (int i=0; i<l; i++)
        frequency[str[i]-'a']++;

    // Push each char frequency into a priority_queue
    priority_queue<int> q;
    for (int i=0; i<MAX_CHAR; i++)
        q.push(frequency[i]);


    // Removal of K characters
    while (k--)
    {
        // Get top element in priority_queue,
        // remove it. Decrement by 1 and again
        // push into priority_queue
        int temp = q.top();
        q.pop();
        temp = temp-1;
        q.push(temp);
    }

    // After removal of K characters find sum
    // of squares of string Value
    int result = 0; // Initialize result
    while (!q.empty())
    {
        int temp = q.top();
        result += temp*temp;
        q.pop();
    }

    return result;
}
