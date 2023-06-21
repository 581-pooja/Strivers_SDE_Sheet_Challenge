#include <bits/stdc++.h> 

static bool comp(pair<int, int> a, pair<int, int> b) {

    double r1 = (double) a.second / (double) a.first;
    double r2 = (double) b.second / (double) b.first;

    return r1 > r2;
}


double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), comp);

    int currWt = 0;
    double res = 0.0;
    double finalVal = 0.0;

    for (int i = 0; i < n; i++) {
      if (currWt + items[i].first <= w) {
            currWt += items[i].first;
            finalVal += items[i].second;
        }

       else {
           int remain = w - currWt;
           finalVal += (items[i].second / (double) items[i].first) * (double) remain;
           break;
       }
    }
   
   return finalVal;
}

// TC: O(N*log N) + O(N) | SC: O(1)