You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
Find out how many ways to assign symbols to make sum of integers equal to target S.

similar to kn-5 que as a+b+c-d+e-f-g = required sum can be written as (a+b+c+e) - (d+f+g) i.e no of subset with given diff.

class Solution {
public:
        int findTargetSumWays(vector<int>& nums, int diff){
        int count=0, sum=0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                count++;
            sum+=nums[i];
        }
        if(diff > sum) return 0;
        if((diff+sum)%2 != 0) return 0;
        int wt=(diff+sum)/2;

        int t[n+1][wt+1];
            for(int i=0;i<n+1;i++){
                for(int j=0;j<wt+1;j++){
                    if(i==0) t[i][j]=0;
                    if(j==0) t[i][j]=1;
                }
            }
            for(int i=1;i<n+1;i++){
                for(int j=1;j<wt+1;j++){
                    if(nums[i-1]==0) t[i][j]=t[i-1][j];
                    else if(nums[i-1] > j) t[i][j]=t[i-1][j];
                    else t[i][j]= t[i-1][j-nums[i-1]] + t[i-1][j];
                }
            }

            return pow(2,count)* t[n][wt];
        }
};
