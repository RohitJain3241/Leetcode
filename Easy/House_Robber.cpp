class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        //i indicates maximum uptil i
        int dp[n+1];
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i=2;i<=n;i++){
            dp[i] = max(dp[i-1] , nums[i-1] + dp[i-2]);
        }
        return dp[n];
    }
};