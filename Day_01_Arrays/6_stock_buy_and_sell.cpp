#include <bits/stdc++.h> 
// Brute Approach
int maximumProfit(vector<int> &arr){
    int maxPro = 0;

    for(int i = 0; i<arr.size(); i++){
        for(int j = i+1; j<arr.size(); j++){
            if(arr[j] > arr[i]){
                maxPro = max(arr[j] - arr[i], maxPro);
            }
        }
    }
    return maxPro;
}

// TC: O(N*N) | SC: O(1)


// Optimal Approach
int maximumProfit(vector<int> &prices){
    int maxPro = 0;
    int minPrice = INT_MAX;

    for(int i = 0; i<prices.size(); i++){
        minPrice = min(minPrice, prices[i]);
        maxPro = max(prices[i]-minPrice, maxPro);
    }
    return maxPro;
}

// TC: O(N) | SC: O(1)