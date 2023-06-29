// using stack concept
# include <bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    if(grid.empty()) return 0;
    int sec = 0;
    int total = 0;
    int count = 0;
    queue <pair<int, int>> rotten;

    // Calculating total oranges = rotten + fresh oranges
    // Pushing all rotten oranges in the queue
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] != 0){
                total++;
            }
            if(grid[i][j] == 2){
                rotten.push({i,j});
            }
        }
    }

    // Direction array
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while(!rotten.empty()){
        int k = rotten.size();
        count += k;
        while(k--){
            int x = rotten.front().first;
            int y = rotten.front().second;
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != 1) continue;
                grid[nx][ny] = 2;
                rotten.push({nx, ny});
            }
        }
        if(!rotten.empty()) sec++;
    }

    return total == count ? sec : -1;
}

// Tc: O(n * n) * 4  (Traverse or iterate every element of grid + 4 direction for every element)
// Sc: O(n * n) (queue)

// Optimized Approach: Using graph concept

# include <bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // { {row, column}, Time}
    queue <pair<pair<int,int>, int>> q;
    int vis[n][m];
    int cntFresh = 0;
    
    // Marking visted array & calculating total fresh Oranges
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else{
                // for no movement cell and not rotten oranges visted mark as zero
                vis[i][j] = 0;
            }
            // counting fresh oranges
            if(grid[i][j] == 1) cntFresh++;
        }
    }
    
    int tm = 0;
    int drow[] = {-1, 0, +1, 0}; // deltaRow (-1 to 1)
    int dcol[] = {0, +1, 0, -1}; // deltaCol (-1 to 1)
    int cnt = 0;
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();
        // traversing the neighbouring cell or oranges
        for(int i = 0; i < 4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                q.push({{nrow,ncol}, t+1});
                vis[nrow][ncol] = 2;
                cnt++;
            }
        }
    }
    
    if(cnt != cntFresh) return -1;
    return tm;
}