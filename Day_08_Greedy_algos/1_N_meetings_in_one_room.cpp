#include <bits/stdc++.h> 

struct meeting{
    int start;
    int end;
    int pos;
};

bool comparator(struct meeting m1, struct meeting m2){
    if(m1.end < m2.end) return true;
    else if(m1.end > m2.end) return false;
    else if(m1.pos < m2.pos) return true;
    return false;
}

vector<int> maximumMeetings(vector<int> &s, vector<int> &e) {
    int n = s.size();
    struct meeting meet[n];
    
    for(int i=0; i<n; i++){
        meet[i].start = s[i];
        meet[i].end = e[i];
        meet[i].pos = i+1;    
    }
    // sorting meetings wrt end time
    sort(meet, meet+n, comparator);

    vector<int> ans;
    // first meeting will always be executed
    int limit = meet[0].end;
    ans.push_back(meet[0].pos);

    for(int i=1; i<n; i++){
        if(meet[i].start > limit){
            limit = meet[i].end;
            ans.push_back(meet[i].pos);
        }
    }
    return ans;
}

// TC: O(N) + O(N*log N) + O(N)
// Inserting + Sorting + Traversing start & finishing time to find maximum meetings
// SC: O(N) (Data structure struct to store end & start time & position) 