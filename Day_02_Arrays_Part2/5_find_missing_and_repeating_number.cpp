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


// Optimal Approach 
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	long long int s = (n*(n+1))/2;
	long long int p = (n*(n+1)*(2*n+1))/6;

	for(int i=0; i<n; i++){
		s -= (long long int) arr[i];
		p -= (long long int) arr[i]*(long long int) arr[i];
	} 

	int missing_ele =(s+(p/s))/2;
	int repeating_ele = missing_ele - s;
	return {missing_ele, repeating_ele};
}

// TC: O(N) | SC: O(1)