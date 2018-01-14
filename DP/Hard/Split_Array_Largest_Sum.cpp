class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        //First we will calculate the sums of all the i,j combinations
        vector< vector<int> > dp(n,vector<int>(n,0));
        //This is for all the single elements
        for(int i=0;i<n;i++)
            dp[i][i] = nums[i];
        for(int sz=2;sz<=n;sz++){
            for(int st=0;st<=n-sz;st++){
                dp[st][st+sz-1] = dp[st][st+sz-2] + dp[st+sz-1][st+sz-1];
            }
        }
        
        vector<vector<int> > memo(n+1,vector<int>(m+1,INT_MAX));
        memo[n][0] = 0;
        //This is starting of the array
        for(int i=n-1;i>=0;i--){
            //This is the value of 'm'
            for(int k=1;k<=min(n-i,m);k++){
                for(int end=i;end<n;end++){
                    memo[i][k] = min( memo[i][k], max( dp[i][end] ,memo[end+1][k-1]) ) ;
                }
            }
        }
        return memo[0][m];
    }
};