class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c ){
        int m = grid.size();
        int n = grid[0].size();

        if(r >= m || r < 0 || c >= n || c < 0 || grid[r][c] == 0 ){
            return 0;
        }

        grid[r][c] = 0;

        int area = 1;

        area += dfs(grid , r+1 , c  );
        area += dfs(grid , r , c-1  );
        area += dfs(grid , r , c+1  );
        area += dfs(grid , r-1 , c  );

        return area;
    }   


    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       int ans = 0;

       for(int i = 0 ; i < m ; i ++){
        for(int j = 0 ; j < n ; j++){
            if(grid[i][j] == 1){
                int area = dfs(grid , i , j  );
                ans = max(ans, area);
            }
        }
       }

       return ans;
    }
};
