class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0 || n==1)
            return false;
        vector<int> dp(n,0);
        vector<int> dp1(n,0);
        for(int i=0;i<n;i++){
            dp[i] = nums[i];
        }
        if(k==0){
            for(int i=0;i<=n-2;i++)
                if(nums[i]==0 && nums[i+1]==0)
                    return true;
            else return false;
        }
        //This sets the size of the moving array!
        for(int siz=2;siz<=n;siz++){
            //This is for the starting index
            for(int j=0;j<=n-siz;j++){
                dp1[j] = dp[j] + nums[j+siz-1];
                if(dp1[j]%k==0)
                    return true;
            }
            dp = dp1;
        }
        return false;
    }
};