class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        if(n==0)
            return result;
        //Step 1: Sorting the given array!
        sort(nums.begin(),nums.end());
        //Now we will create a vector containing a pair 
        //with 1st index as the number of elements 
        //second index as the index of that largest divisor element!
        vector<pair<int,int > > dp;
        //initialization
        dp.push_back(make_pair(1,0));
        int maxi=1,maxindex=0;
        //Step 2: Defining the dp
        for(int i=1;i<n;i++){
            dp.push_back(make_pair(1,nums[i]));
            for(int j=i-1;j>=0;j--){
                //If i'th element is divisible by j'th element
                //and also it has greater number of factors than previously got solution
                if(nums[i]%nums[j]==0 && dp[i].first < 1+dp[j].first){
                    dp[i].first = 1+dp[j].first;
                    dp[i].second = j;
                }
            }
            //Step 3: Finding the maximum value in the first index of the dp
            if(dp[i].first > maxi){
                maxi = dp[i].first;
                maxindex = i;
            }
        }
        
        //Step 4: Backtracking to get all the elements corresponding to it!
        while(dp[maxindex].first != 1){
            result.push_back(nums[maxindex]);
            maxindex = dp[maxindex].second;
        }
        result.push_back(nums[maxindex]);
        //revert the vector
        reverse(result.begin(),result.end());
        return result;
    }
};