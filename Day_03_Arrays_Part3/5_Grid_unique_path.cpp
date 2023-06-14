// brute Force
int countPaths(int i, int j, int n, int m){
	// base condition
	if(i == (n-1) && j == (m-1)) return 1;

	// Out of bounds condtion
	if(i >= n || j >= m) return 0;

	// Traversing the grid or tree
	else return countPaths(i+1, j, n, m) + countPaths(i, j+1, n, m);
}

int uniquePaths(int m, int n) {
	return countPaths(0,0,n,m);
}

// TC & SC is exponential in nature

// Optimal Approach:
int uniquePaths(int m, int n) {
	int N = n+m-2;
	int r = n-1;
	double res = 1;
	for(int i=1; i<=r; i++){
		res = res * (N-r+i)/i;
	}
	return (int)res;
}

// TC: O(n-1) or O(m-1) | SC: O(1)