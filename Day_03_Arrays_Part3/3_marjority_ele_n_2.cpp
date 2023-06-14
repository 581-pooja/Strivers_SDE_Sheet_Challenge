// Brute Approach:
int findMajorityElement(int nums[], int n) {
	for(int i=0; i<n; i++){
		int count = 1;
		for(int j=i+1; j<n; j++){
			if(nums[j] == nums[i]) count++;
		}
		if(count > n/2){
			return nums[i];
		}
	}
	return -1;
}
// TC: O(N*N) | SC: O(1)

// Better Approach:
int findMajorityElement(int nums[], int n) {
	unordered_map <int,int> mp;
	// Putting element in hashmap with count
	for(int i=0; i<n; i++){
		mp[nums[i]]++;
	}
	// Iterating Hashmap to get count
	for(auto x: mp){
		if(x.second > n/2){
			return x.first;
		}
	}
	return -1;
}
// TC: O(N) (for loop) | SC: O(N) (Unorderd_map)

// Optimal Approach:
int findMajorityElement(int nums[], int n) {
	int count = 0;
	int element;

	for(int i=0; i<n; i++){
		if(count == 0){
			element = nums[i];
		}
		if(element == nums[i]) count++ ;
		else count-- ;
	}
	return element;
}
// Moore Voting Algorithm
// TC: O(N) (for loop) | SC: O(1)