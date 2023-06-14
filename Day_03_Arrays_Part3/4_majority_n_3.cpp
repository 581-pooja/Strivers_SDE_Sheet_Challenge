// Better approach:
vector<int> majorityElementII(vector<int> &arr){
    int n = arr.size();
    vector<int> ans;
    unordered_map <int,int> mp;

	// Putting element in hashmap with count
	for(int i=0; i<n; i++){
		mp[arr[i]]++;
	}

	// Iterating Hashmap to get count
	for(auto x: mp){
		if(x.second > n/3){
			ans.push_back(x.first);
		}
	}
	return ans;
}

// Tc: O(N) | SC: O(N) (unordered_map)