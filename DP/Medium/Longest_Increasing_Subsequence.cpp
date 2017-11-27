class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(),m=0;
        int dp[n+1];
        dp[0] = 0;
        for(int i=1;i<n+1;i++){
            dp[i] = 1;
            for(int j=i-1;j>=1;j--){
                if(nums[j-1]<nums[i-1])
                    dp[i] = max(dp[i],1+dp[j]);
            }
        }
        for(int i=0;i<n+1;i++)
            m = max(m,dp[i]);
        return m;
    }
};