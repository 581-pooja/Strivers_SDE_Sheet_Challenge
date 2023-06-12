/*
Given an integer array arr, find the contiguous subarray (containing at least one number) which
has the largest sum and returns its sum and prints the subarray

Example 1:
Input: arr = [-2,1,-3,4,-1,2,1,-5,4] 
Output: 6 
Explanation: [4,-1,2,1] has the largest sum = 6. 

Examples 2: 
Input: arr = [1] 
Output: 1 
Explanation: Array has only one element and which is giving positive sum of 1.
*/

// Optimal Approach
long long maxSubarraySum(int arr[], int n)
{
    long long maxi = arr[0];
    long long sum = 0;
    
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum > maxi){
            maxi = sum;
        }

        if(sum < 0){
            sum = 0;
        }
    }
    return maxi;
}
// TC: O(N) | SC: O(1)