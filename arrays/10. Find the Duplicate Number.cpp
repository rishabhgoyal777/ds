Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.
Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

nums = [1,1,1,1]
output: 1

time O(n)
space O(n)
====================
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       map<int, int> mp;

        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==1){
                return nums[i];
            }
            else{
                mp[nums[i]]=1;
            }
        }
    return -1;
    }
};

time O(n)
space O(1)
====================
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[nums[i]%n]+= n;  // index pe jo element hai us index pe n plus krdiya // mod liya kyoki agr pehle se n plus kiya ho kabhi to original index nhi mile
        }

        for(int i=0;i<n;i++){
            if(nums[i]/n > 1) //mtlb n plus hua hai 1 bar se jyada
                return i;
        }
        return -1;
    }
};
