#include <bits/stdc++.h>
// brute Force
int findDuplicate(vector<int> &arr, int n){
	sort(arr.begin(), arr.end());
	for(int i=0; i<n-1; i++){
		if(arr[i] == arr[i+1])
			return arr[i];
	}
}
// TC: O(N*Log N)+O(N) (Sorting + For loop)
// SC: O(1)



// Better Force
int findDuplicate(vector<int> &arr, int n){
	int freq[n+1] = {0};
	for(int i=0; i<n; i++){
		if(freq[arr[i]] == 0){
			freq[arr[i]]++;
		}
		else{
			return arr[i];		
		}
	}
}
// TC: O(N)  (For loop)
// SC: O(N) (Frequency Array)

