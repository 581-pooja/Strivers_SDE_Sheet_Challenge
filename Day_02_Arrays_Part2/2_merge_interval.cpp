#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

// Optimal Approach
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> merged;
    sort(intervals.begin(), intervals.end());

    for(int i=0; i<intervals.size(); i++){
        if(merged.empty() || merged.back()[1] < intervals[i][0]){
            vector<int> v = {intervals[i][0], intervals[i][1]};
            merged.emplace_back(v);
        }
        else{
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        }
    }
    return merged;
}
// TC: O(N*logN) + O(N) (Sorting + For loop)
// SC: O(N) (O(1) since we are returning merged as ans)