

You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.

The right interval for an interval i is an interval j such that startj >= endi and startj is minimized. Note that i may equal j.

Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.
vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        vector<int> v;
        int n= intervals.size();
        
        if(n==1)    return {-1};
        
        int ele= INT_MAX;
        int idx= -1;
        
        for(int i=0; i<n; i++)
        {
            ele= INT_MAX;
            int second= intervals[i][1];
            for(int j=0; j<n; j++) 
            {
                if(i != j && intervals[j][0] < ele && intervals[j][0] >= intervals[i][1])
                {
                    ele= intervals[j][0];
                    idx= j;
                }
            }
            if(ele== INT_MAX) {
                v.push_back(-1);
            }
            else {
                v.push_back(idx);
            }
        }
        
        return v;
    }



    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        vector<int> v;
        int n= intervals.size();
        
        if(n==1)    return {-1};

        map<int, int> mp;
        
        for(int i=0; i<n; i++) {
            mp[intervals[i][0]]= i;
        }
        
        for(int i=0; i<n; i++)
        {
            auto it= mp.lower_bound(intervals[i][1]);
            
            if(it != mp.end()) {
                v.push_back(it->second);
            }
            else {
                v.push_back(-1);
            }
        }
        
        return v;
    }