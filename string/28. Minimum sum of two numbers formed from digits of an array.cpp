N = 6
Arr[] = {6, 8, 4, 5, 2, 3}
Output: 604
Explanation: The minimum sum is formed 
by numbers 358 and 246.
  
//ans comes when we sort array and take num1 with even indexes and take num2 with odd indexes


//sum of numbers denoted by strings 
string sumofstrings(string a, string b){  
        int i1 = a.length()-1;
        int i2 = b.length()-1;
        
        int carry = 0;
        string result="";
        
        while(i1>=0 || i2>=0){
            int num1=0;
            if(i1>=0){
                num1=a[i1]-'0';
                i1--;
            }
            int num2=0;
            if(i2>=0){
                num2=b[i2]-'0';
                i2--;
            }
            
            int sum = num1 + num2 + carry;
            int unit = sum%10;
            carry = sum/10;
            result.append(to_string(unit));
        }
        if(carry>0){
            result.append(to_string(carry));
        }
        reverse(result.begin(), result.end());
        return result;
    }

    string solve(int arr[], int n) {
        sort(arr, arr+n);
        
        int i=0;
        string n1;
        string n2;
        
        for(int i=0;i<n;i++){
            if(i%2==0){
                int c = arr[i];
                if(c==0 && n1.length()==0 ){
                    continue;
                }
                n1.append(to_string(c));
            }
            else{
                int c = arr[i];
                if(c==0 && n2.length()==0 ){
                    continue;
                }
                n2.append(to_string(c));
            }
        }
        
        return sumofstrings(n1,n2);
    }
