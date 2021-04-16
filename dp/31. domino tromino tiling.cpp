We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape. These shapes may be rotated.

class Solution {
public:
    int numTilings(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int t[n+1];

        t[0]=t[1]=1;
        t[2]=2;
        for(int i=3;i<=n;i++){
            t[i]=(2*t[i-1]% 1000000007 + t[i-3]% 1000000007) % 1000000007;
        }
        return t[n];
    }
};
