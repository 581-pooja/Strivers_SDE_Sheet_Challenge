// Brute Force
bool searchMatrix(vector<vector<int>>& mat, int target) {
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[0].size(); j++){
            if(mat[i][j] == target) return true;
        }
    }
    return false;
}
// TC: O(M*N) | SC: O(1)

// Better Approach
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();
    int i=0, j=m-1;
    while(i<n && j>=0 ){
        if(mat[i][j] == target) return true;
        if(mat[i][j] < target) i++;
        else j--;
    }
    return false;
}
// TC: O(M*N) | SC: O(1)

bool searchMatrix(vector<vector<int>>& mat, int target) {
    if(!mat.size()) return false;
    int n = mat.size();
    int m = mat[0].size();
    
    int low = 0;
    int high = (n*m)-1;
    
    while(low <= high){
        int mid = (low + high)/2;
        if(mat[mid/m][mid%m] == target) return true;
        if(mat[mid/m][mid%m] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}
// TC: O(log^2(m*n)) | SC: O(1)