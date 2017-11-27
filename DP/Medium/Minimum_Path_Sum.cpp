class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(),cols = grid[0].size();
        //This is the shortest sum of path from i,j!
        int dp[rows][cols];
        dp[rows-1][cols-1] = grid[rows-1][cols-1];
        //This is for the last row
        for(int j=cols-2;j>=0;j--)
            dp[rows-1][j] = grid[rows-1][j] + dp[rows-1][j+1];
        //This is for the last column
        for(int i=rows-2;i>=0;i--)
            dp[i][cols-1] = grid[i][cols-1] + dp[i+1][cols-1];
        for(int i=rows-2;i>=0;i--){
            for(int j=cols-2;j>=0;j--){
                dp[i][j] = grid[i][j] + min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};