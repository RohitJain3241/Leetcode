class Solution {
public:
    int rob(vector<int>& nums) {
        int  n = nums.size();
        if(n==0)
            return 0;
        //This saves the optimal value uptil that.
        //mark saves whether last element is used or not.
        int dp[n+1],mark[n+1];
        dp[n] = 0;mark[n]=0;
        dp[n-1] = nums[n-1];mark[n-1]=1;
        for(int i=n-2;i>=0;i--){
            dp[i] = max(nums[i] + dp[i+2],dp[i+1]);
            if(dp[i]==nums[i]+dp[i+2] && mark[i+2]==1)
                mark[i]=1;
            else if(dp[i]==dp[i+1] && mark[i+1]==1)
                mark[i]=1;
            else
                mark[i]=0;
        }
        //This means first and last element is included in it! 
        if(mark[0]==1 && n>1 && dp[0]==nums[0]+dp[2]){
            //This is for the case when last is not included
            int dp1[n];
            //we need to return the max of 2 conditions
            //when first is not there and when last is not there
            dp1[n-1] = 0;
            dp1[n-2] = nums[n-2];
            for(int i=n-3;i>=0;i--){
                dp1[i] = max(nums[i] + dp1[i+2],dp1[i+1]);
            }
            //return maximum of both the cases!
            return max(dp1[0],dp[1]);
        }
        else 
            return dp[0];  
    }
};