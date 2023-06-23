#include <bits/stdc++.h> 
// Brute
vector<int> nextGreater(vector<int> &arr, int n) {
    vector <int> nge(n, -1);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j] > arr[i]) {
                nge[i] = arr[j];
                break;
            }
        }
    }
    return nge;
}
// TC: O(N*N) | SC: O(1)

#include <bits/stdc++.h> 
// Optimal Approach:
vector<int> nextGreater(vector<int> &arr, int n) {
    vector <int> nge(n,-1);
    stack <int> st;
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            nge[i] = st.top();
        }
        else nge[i] = -1;
        st.push(arr[i]);
    }
    return nge;
}
// TC: O(N) | SC: O(N) (For stack)