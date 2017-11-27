class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int summer = 0,n=nums.size();
        for(int i=0;i<n;i++) summer+=nums[i];
        if(summer%2!=0) return false;
        //Until i'th element and sum=j
        //starting from1 to n
        int dp[n+1][summer+1];
        for(int i=0;i<=n;i++) dp[i][0] = 1;
        for(int i=1;i<=summer;i++) dp[0][i] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=summer;j++){
                dp[i][j] = dp[i-1][j];
                if(j>=nums[i-1])
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i][j];
            }
        }
        return (dp[n][summer/2]==1);
    }
};