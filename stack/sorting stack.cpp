ITERATIVE

void SortedStack :: sort()
{
   vector<int> v;
   while(!s.empty()){
   v.push_back(s.top()); s.pop();
   }

   std::sort(v.begin(), v.end());

   for (auto x : v){
       s.push(x);
   }
}


RECURSION(important)

void sortedInsert(stack<int> &s, int x)
{
	if(s.empty() or x>s.top())
	{
		s.push(x);
		return;
	}
	int temp = s.top();
	s.pop();
	sortedInsert(s,x);
	s.push(temp);
}

void SortedStack :: sort()
{
	if(!s.empty())
	{
		int x = s.top();
		s.pop();
		sort();
		sortedInsert(s,x);
	}
}
