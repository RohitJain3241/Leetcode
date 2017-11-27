//Consider important test cases like - [0,0,0,0,0,0,0,0,1] Or [0,0]
//Also when S is not in range. 

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n=nums.size();
        if(n==0){
            if(S==0)
                return 1;
            else
                return 0;
        }
        int summer = 0;
        //Thi gives us the range of the sum in both +ve and -ve side
        for(int i=0;i<n;i++)
            summer += nums[i];
        //If the sum given is greater than the max. sum possible
        //Or less than the most negative sum possible
        //return 0 
        if(S>summer || S<-summer)
            return 0;
        //This keeps the number of ways we have sum=j until i'th element 
        //0 to summer-1 is for -ve,
        //summer is for 0
        //summer+1 to 2*summer is for +ve
        vector<vector<int > > dp(n,vector<int>(2*summer+1,0));
        //int dp[n][2*summer+1];
        //For the first element,we see that that only sum that could be found is this!
        dp[0][summer + nums[0]] = dp[0][summer - nums[0]] = 1;
        //Checking if it is 0!
        if(nums[0]==0)
            dp[0][summer] = 2;
        //This will see the starting 
        for(int i=1;i<n;i++){
            //This will see for the range of sum values
            for(int j=-summer;j<=summer;j++){
                //If we can find any combination for the given sum=j 
                if(summer+j-nums[i] >= 0)
                    dp[i][summer+j] += dp[i-1][summer+j-nums[i]];
                if(summer+j+nums[i] < 2*summer+1)
                    dp[i][summer+j] += dp[i-1][summer+j+nums[i]];
            }
        }
        return dp[n-1][summer+S];
    }
};