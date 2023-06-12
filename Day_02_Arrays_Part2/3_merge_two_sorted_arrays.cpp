#include <bits/stdc++.h>

// Brute Force
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	vector<int> arr;
	for(int i=0; i<m; i++){
		arr.push_back(arr1[i]);
	}
	for(int j=0; j<n; j++){
		arr.push_back(arr2[j]);
	}
	sort(arr.begin(), arr.end());
	return arr;
}
// TC: O(N+M) | SC: O(N+M)