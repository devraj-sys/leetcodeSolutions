class Solution {
public:

    void dfs(vector<vector<int>>& image, int r, int c, int colour , int orgSP){
        int m = image.size();
        int n = image[0].size();

        if(r >= m || r < 0 || c >= n || c < 0 || image[r][c] != orgSP){
            return;
        }

        image[r][c] = colour;

        dfs(image , r+1 , c , colour , orgSP);
        dfs(image , r , c-1 , colour , orgSP);
        dfs(image , r , c+1 , colour , orgSP);
        dfs(image , r-1 , c , colour , orgSP);
    }



    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int orgSP = image[sr][sc];
        if (orgSP == color) return image;

        dfs(image , sr , sc , color , orgSP);
        return image;

    }
};