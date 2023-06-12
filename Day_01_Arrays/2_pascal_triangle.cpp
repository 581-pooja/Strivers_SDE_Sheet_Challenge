#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) {
    vector<vector<long long int>> m(n);
    
    for(int i = 0; i<n; i++){
        m[i].resize(i+1);
        m[i][0] = m[i][i] = 1;  
        
        for(int j=1; j<i; j++){
            m[i][j] = m[i-1][j-1] + m[i-1][j];
        }
    }
    return m;
}
// TC: O(N*N) | SC: O(N*N)