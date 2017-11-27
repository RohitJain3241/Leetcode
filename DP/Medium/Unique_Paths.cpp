class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0 || n==0)
            return 1;
        //This saves the number of ways i,j could be reached
        int dp[m][n];
        //For the leftmost line
        for(int i=0;i<m;i++)
            dp[i][0] = 1;
        //For the 1st row
        for(int i=0;i<n;i++)
            dp[0][i] = 1;
        //This is for i'th row
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};
