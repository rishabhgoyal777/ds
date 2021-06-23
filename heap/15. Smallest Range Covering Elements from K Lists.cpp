You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
  
//pushing first element of every list in heap. and keeping min and max in a variable min will be the top of heap. check range = max-min and keep range windows in low and hogh. if it is les than the previously calculated range then update range, low and high values 
  
class Solution {
  public:    
    //every eleemnt has 4 attributes
    class element{
        public:
        int value;
        int arrind;
        int ind;
        int arrsize;
        
        element(int val, int row, int index, int size){
            value = val;
            arrind = row;
            ind = index;
            arrsize = size;
        }
    };
    
    struct compare{
        bool operator()(element a, element b){
            return a.value > b.value;
        }
    };
    
    vector<int> smallestRange(vector<vector<int>>& arr) {
      int mn=INT_MAX;
      int mx=INT_MIN;
      vector<int> v;
      int range=INT_MAX;
      priority_queue<element, vector<element>, compare > minhp;

      int k = arr.size();
      int low, high;

      for(int i=0;i<k;i++){
          minhp.push(element(arr[i][0], i, 0, arr[i].size()));
          mx=max(mx,arr[i][0]);
      }

      while(!minhp.empty()){
          element top = minhp.top();
          minhp.pop();
          int mn=top.value;

          if(mx-mn < range){
              range=mx-mn;
              low=mn;
              high=mx;
          }

          if(top.ind == top.arrsize -1) //when any list completes the calculated range will be the answer.
              break;

          top.ind++;
          minhp.push(element(arr[top.arrind][top.ind], top.arrind, top.ind, arr[top.arrind].size()));
          mx= max(mx, arr[top.arrind][top.ind]);

      }
      v.push_back(low);
      v.push_back(high);
      return v;
  }
};
