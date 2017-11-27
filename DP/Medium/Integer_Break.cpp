class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        dp[1] = 0;
        dp[2] = 1;
        for(int i=3;i<=n;i++){
            dp[i] = -1223;
            for(int j=1;j<=i-1;j++){
                dp[i] = max( max( dp[i-j]*j, max(dp[j]*(i-j), max( dp[i-j]*dp[j] , (i-j)*j)) ), dp[i] ) ;
            }
        }
        return dp[n];
    }
};