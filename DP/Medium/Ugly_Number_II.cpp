class Solution {
public:
    int nthUglyNumber(int n) {
        int m,i2,i3,i5;
        i2 = i3 = i5 = 1;
        int dp[1691];
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            m = min(dp[i2]*2,min(dp[i3]*3,dp[i5]*5));
            if(m==dp[i2]*2){
                dp[i] = dp[i2++]*2;
            }
            if(m==dp[i3]*3){
                dp[i] = dp[i3++]*3;
            }
            if(m==dp[i5]*5){
                dp[i] = dp[i5++]*5;
            }
        }
        return dp[n];
    }
};