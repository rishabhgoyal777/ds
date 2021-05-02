Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
The replacement must be in place and use only constant extra memory.

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int index;
        int i;
        //starting from end find number which is smaller than its next number. it willl be i-1 index
        for(i=n-1;i>0;i--){
            if(nums[i] > nums[i-1]){
                break;
            }
        }
        if(i==0){  //greatest permutation. next permutation is the smallest no.
            sort(nums.begin(),nums.end());
            return;
        }

        //find number justgreater than i-1 on its right and swap and sort the next lest on right side
        index=nums[i-1];
        int nextgreater=i;

        for(int j=i+1;j<n;j++){
            if(nums[j]>index && nums[j]<nums[nextgreater]){
                nextgreater=j;
            }
        }
        swap(nums[i-1], nums[nextgreater]);

        sort(nums.begin()+i,nums.end());
    }
};
