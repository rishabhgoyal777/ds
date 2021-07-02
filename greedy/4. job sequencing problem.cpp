// struct Job 
// { 
//     int id;	 // Job Id 
//     int dead; // Deadline of job 
//     int profit; // Profit if job is over before or on deadline 
// };
//

class Solution 
{
    public:
    
    struct compare{
      bool operator()(Job a, Job b){
          return (a.profit > b.profit);
      }  
    };
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, compare());
        int maxdedline=INT_MIN;
        for(int i=0;i<n;i++){
            maxdedline=max(maxdedline,arr[i].dead);
        }
        
        int slot[maxdedline+1];
        memset(slot, -1, sizeof(slot));
        
        int num=0;
        int prof=0;
        
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(slot[j] == -1){
                    slot[j]=i;
                    num++;
                    prof+=arr[i].profit;
                    break;
                }
                
            }
        }
        vector<int> res;
        res.push_back(num);
        res.push_back(prof);
        return res;
        
    } 
