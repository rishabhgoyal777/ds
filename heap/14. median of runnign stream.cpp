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


==============================================================================
 
 void printMedians(double arr[], int n)
{
    // max heap to store the smaller half elements
    priority_queue<double> s;
  
    // min heap to store the greater half elements
    priority_queue<double,vector<double>,greater<double> > g;
  
    double med = arr[0];
    s.push(arr[0]);
  
    cout << med << endl;

    for (int i=1; i < n; i++)
    {
        double x = arr[i];
  
        // case1(left side heap has more elements)
        if (s.size() > g.size())
        {
            if (x < med)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);
  
            med = (s.top() + g.top())/2.0;
        }
  
        // case2(both heaps are balanced)
        else if (s.size()==g.size())
        {
            if (x < med)
            {
                s.push(x);
                med = (double)s.top();
            }
            else
            {
                g.push(x);
                med = (double)g.top();
            }
        }
  
        // case3(right side heap has more elements)
        else
        {
            if (x > med)
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
                s.push(x);
  
            med = (s.top() + g.top())/2.0;
        }
  
        cout << med << endl;
    }
}
