class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int M = 1000000000 + 7;
        int x[4] = {1,-1,0,0};
        int y[4] = {0,0,1,-1};
        //For every coordinate we will calculate the number of ways to move out 
        long long dp[m+1][n+1][N+1];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                dp[i][j][0] = 0;
        for(int k=1;k<=N;k++){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    dp[i][j][k] = 0;
                    for(int l=0;l<4;l++){
                        if(i+x[l]>=m || i+x[l]<0 || j+y[l]>=n || j+y[l]<0)
                            dp[i][j][k] = (dp[i][j][k] + 1)%M;
                        else
                            dp[i][j][k] = (dp[i][j][k] + dp[i+x[l]][j+y[l]][k-1])%M;
                    }
                }
            }
        }
        return dp[i][j][N]%M;
    }
};