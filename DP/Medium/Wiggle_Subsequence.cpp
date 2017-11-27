class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(),m=1;
        if(n==0)
            return 0;
        //first index is the element uptil i
        //2nd index's 1 tells if previous was (+)ve
        int dp[n][2];
        dp[0][0] = dp[0][1] = 1;
        for(int i=1;i<n;i++){
            dp[i][0] = dp[i][1] = 1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])
                    dp[i][1] = max(1+dp[j][0],dp[i][1]);
                else if(nums[j]>nums[i])
                    dp[i][0] = max(1+dp[j][1],dp[i][0]);
            }
            if(m < max(dp[i][0],dp[i][1]))
                m = max(dp[i][0],dp[i][1]);
        }
        return m;
    }
};