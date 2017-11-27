class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        //LCS ending with i'th element
        //Making the vector of pairs with 1st index as length of LCS
        //and 2nd index is the number of such largest LCS
        vector<pair<int,int > > dp(n,make_pair(0,0));
        //This saves the max length of LCS.
        int maxi=1,res=1;
        //Length of LCS for 1st element is 1 and 
        //number of such combinations is 1
        dp[0] = make_pair(1,1);
        for(int i=1;i<n;i++){
            dp[i] = make_pair(1,1);
            for(int j=i-1;j>=0;j--){
                //If the previous element is smaller than present element
                if(nums[j]<nums[i]){
                    //If the length of the Lcs including this element and j'th element is greater
                    if(dp[i].first < 1+dp[j].first){
                        dp[i].first = 1+dp[j].first;
                        dp[i].second = dp[j].second;
                    }
                    //If another lcs occurs with same length
                    else if(dp[i].first == 1+dp[j].first)
                        dp[i].second += dp[j].second;
                }
            }
            //saving max. length so far and number of such combinations
            if(maxi<dp[i].first){
                maxi = dp[i].first;
                res = dp[i].second;
            }
            else if(maxi==dp[i].first)
                res += dp[i].second;
        }
            
        return res;
    }
};