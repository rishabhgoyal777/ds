 s1 - s2 = diff
 s1 + s2 = sum of ARRAY
+_____________________
 2 s1 = diff +sum

 s1= (diff + sum)/2   diff is given, sum we can calculate therefore problem reduces to count of subset sums with given sum


int count=0, sum=0;
for(int i=0;i<n;i++){
    if(nums[i]==0)
      count++;
    sum+=nums[i];
}
if(diff > sum) return 0;
if((diff+sum)%2 != 0) return 0;
int s1=(diff+sum)/2;

int t[n+1][s1+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<s1+1;j++){
            if(i==0) t[i][j]=0;
            if(j==0) t[i][j]=1;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<s1+1;j++){
            if(nums[i-1]==0) t[i][j]=t[i-1][j];              // nhi include krna
            else if(nums[i-1] > j) t[i][j]=t[i-1][j];
            else t[i][j]= t[i-1][j-nums[i-1]] + t[i-1][j];
        }
    }     return pow(2,count)* t[n][s1];
    }
