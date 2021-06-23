 double median;
    
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int> > minpq;
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if (maxpq.empty()) 
    		maxpq.push(x);
    		
    	else if (x > maxpq.top()) 
    		minpq.push(x);
    	
    	else{ //x <= maxpq.top() =>have to push in maxhp
        
        //if already size is greater
    	  if(minpq.size() < maxpq.size())
        	{
        		minpq.push(maxpq.top());
        		maxpq.pop();
        		maxpq.push(x);
        	}
        	else //simply push
        		maxpq.push(x);
    	}

    	balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(abs(maxpq.size() - minpq.size() )>1){
            
            if(maxpq.size() > minpq.size()){
                minpq.push(maxpq.top());
                maxpq.pop();
            }
            if(maxpq.size() < minpq.size()){
                maxpq.push(minpq.top());
                minpq.pop();
            }
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(maxpq.size() == minpq.size()){
            median=(maxpq.top() + minpq.top())/2;
        }
        else if(maxpq.size() > minpq.size()){
            median=maxpq.top();
        }
        else{
            median= minpq.top();
        }
        return median;
    }
