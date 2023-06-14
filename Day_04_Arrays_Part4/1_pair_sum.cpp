// burte Force
vector<vector<int>> pairSum(vector<int> &arr, int s){
   int n = arr.size();
   vector<vector<int>> finalAns;
   for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
         if(arr[i] + arr[j] == s){
            vector <int> ans;
            ans.push_back(arr[i]);
            ans.push_back(arr[j]);
            finalAns.push_back(ans);
         }
      }
   }
   return finalAns;
}

