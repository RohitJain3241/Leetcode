class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        //This will save the start and the end!
        int dp[n][n],summer=0;
        for(int i=0;i<n;i++)
            summer += nums[i];
        for(int i=0;i<n;i++)
            dp[i][i] = nums[i];
        for(int i=0;i<n-1;i++)
            dp[i][i+1] = max(nums[i],nums[i+1]);
        for(int size=3;size<=n;size++){
            for(int start=0;start<=n-size;start++)
                dp[start][start+size-1] = max(  nums[start] + min(dp[start+2][start+size-1]  ,  dp[start+1][start+size-2] ) ,                                                                 nums[start+size-1] + min(dp[start+1][start+size-2]  ,  dp[start][start+size-3] )  );
        }
        //return true if sum of the elemnts of first turn guy is greater than 2nd!
        return summer-dp[0][n-1] <= dp[0][n-1];
    }
};