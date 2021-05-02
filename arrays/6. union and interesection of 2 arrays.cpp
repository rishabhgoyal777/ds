class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        int i=0,j=0;
        int n=a.size();
        int m=b.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        unordered_set<int> v;
        while(i<n && j<m){
            if(a[i] < b[j]){
                // v.insert(a[i]);
                i++;
            }
            else if(a[i] > b[j]){
                // v.insert(b[j]);
                j++;
            }
            else{
                v.insert(a[i]);
                i++; j++;
            }
        }

        // while(i<n){
        //     v.insert(a[i++]);
        // }
        // while(j<m){
        //     v.insert(b[j++]);
        // }
        vector<int> res;
        for(auto x:v){
            res.push_back(x);
        }
        return res;

    }
};
