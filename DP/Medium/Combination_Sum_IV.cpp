class Solution {
    int f(vector<int>& nums, int target,vector<int>& dp){
        if(dp[target]!=-1)
            return dp[target];
        int res=0;
        if(target==0)
            return dp[target] = 1;
        for(int i=0;i<nums.size();i++){
            if(target-nums[i]>=0)
                res += f(nums,target-nums[i],dp);
        }
        return dp[target] = res;
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(1000001,-1);
        return f(nums,target,dp);
    }
};