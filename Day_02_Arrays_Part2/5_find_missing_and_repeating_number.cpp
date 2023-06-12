#include <bits/stdc++.h>

// Brute Force 
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	vector<int> ans;
	vector<int> freq(n+1,0);
	for(int i=0; i<n; i++){
		freq[arr[i]]++;
	}

	int missingNum, repeatingNum;

	for(int i=1; i<=n; i++){
		if(freq[i] == 0 ){
			missingNum = i;
		}
		if(freq[i] > 1){
			repeatingNum = i;
		}
	}

	return {missingNum,repeatingNum};
	
}

// TC: O(N) + O(N) | SC: O(N) (Frequency Array)