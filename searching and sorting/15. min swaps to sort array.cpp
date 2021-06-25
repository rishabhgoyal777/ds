 10  19  6  3  5
  0  1   2  3  4   
   
VECTOR<ELE, INDEX> V {10,0} {19,1} {6,2} {3,3} {5,4}

AFTER SORTING
{3,3} {5,4} {6,2} {10,0} {19,1} . THIS IS THE SORTED ORDER. NOW WE ARE CONVERTINNG FROM SORTED TO THE ONE GIVEN IN QUESTION. AND COUNTING SWAPS

NOW CHECK IF NOT ON RIGHT INDEX SWAP TO THE INDEX IT HAS TO BE. INCREASE COUNT. AND i-- SINCE WE NEED TO ALSO CHECK FOR ELEMENT THAT HAS BEEN NOW SWAPPED TO iTH INDEX 

int minSwaps(vector<int>&arr)
	{
	    int count=0;
	    int n= arr.size();
	    vector<pair<int, int>> v;
	    for(int i=0;i<n;i++){
	        v.push_back({arr[i], i});
	    }
	    sort(v.begin(), v.end());
	    
	    for(int i=0;i<n;i++){
	        if(i!=v[i].second){
	            count++;
	            swap(v[i], v[v[i].second]);
	            i--;
	        }
	    }
	    return count;
	}
