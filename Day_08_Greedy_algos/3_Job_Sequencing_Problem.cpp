#include <bits/stdc++.h>
static bool cmp(vector<int>&a, vector<int>&b){
    return a[1]>b[1];
}
int jobScheduling(vector< vector<int> > &jobs)
{
    // jobs {deadline, profit}
    sort(jobs.begin(), jobs.end(), cmp);
    int n=jobs.size();
    int profit=0;

    int maxi = jobs[0][0];
    for(int i=1; i<n; i++){
        maxi = max(maxi, jobs[i][0]);
    }

    vector<int> slot(maxi+1, -1);

    for(int i=0; i<n; i++){
        for(int j=jobs[i][0]; j>0; j--){
            if(slot[j]==-1){ //prevents us from reconsidering the same deadline.
                slot[j]=i;
                profit += jobs[i][1];
                break;
            }
        }
    }
    return profit;
}

// TC: O(N*log N) + O(N*M) | SC: O(M) : M: slots i.e maxi deadline : N : no of jobs