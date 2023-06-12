#include <bits/stdc++.h> 

// eg. 1,3,5,4,2 -> 1,4,2,3,5

// Optimal Approach:
vector<int> nextPermutation(vector<int> &nums, int n)
{
    int k, l;
    for(k = n-2; k >= 0; k--){
        if(nums[k] < nums[k+1]){
            break;
        }
    }

    if(k<0){
        reverse(nums.begin(), nums.end());
    }
    else{
        for(l = n-1; l>k; l--){
            if(nums[k] < nums[l]){
                break; 
            }
        }

        swap(nums[k], nums[l]);
        reverse(nums.begin()+ k + 1, nums.end());
    }
    return nums;
}
// TC: O(N) + O(N) + O(N) (For loop + for loop + reverse) ~ O(3N) 
// SC: O(1)