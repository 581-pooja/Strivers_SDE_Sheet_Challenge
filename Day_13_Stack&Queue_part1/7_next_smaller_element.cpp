// Brute Force:
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n,-1);
   for(int i=0; i<n; i++){
       for(int j=i+1; j<n; j++){
           if(arr[i] > arr[j]){
               ans[i] = arr[j];
               break;
           }
       }
   }
   return ans;
}

// Optimal Approch:
#include <bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector <int> nse(n,-1);
    stack <int> st;
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            nse[i] = st.top();
        }
        else nse[i] = -1;
        st.push(arr[i]);
    }
    return nse;
}