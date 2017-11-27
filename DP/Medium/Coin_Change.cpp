class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n+1][amount+1];
        for(int i=0;i<=amount;i++)
            dp[n][i] = 999999;
        //We don't need any coin to represent 0 as sum!
        for(int i=0;i<=n;i++)
            dp[i][0] = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=amount;j++){
                dp[i][j] = 999999;
                if(coins[i]<=j)
                    dp[i][j] = 1 + dp[i][j-coins[i]];
                dp[i][j] = min(dp[i][j],dp[i+1][j]);
            }
        }
        if(dp[0][amount]==999999)
            return -1;
        return dp[0][amount];
    }
};