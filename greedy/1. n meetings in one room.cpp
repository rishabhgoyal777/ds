struct compare{
        bool operator()(pair<int, int> a, pair<int, int> b){
            return a.second < b.second ;
        }
    };

    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({start[i], end[i]});
        }

        sort(v.begin(), v.end(), compare());

        int count=1;
        int etime=v[0].second;

        for(int i=0;i<n;i++){
            if(v[i].first > etime){
                count++;
                etime=v[i].second;
            }
        }
        return count;
    }
