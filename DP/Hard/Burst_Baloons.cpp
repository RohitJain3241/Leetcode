//This is the same as matrix multiplication problem!
//There also we found best solution for the left side
//and right side and then combined them

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        //This will save the max. coins after popping all baloons in (i,j)
        vector<vector<int> > dp(n+2,vector<int>(n+2,0));
        for(int sz=1;sz<=n;sz++){
            for(int start=1;start<=n-sz+1;start++){
                int end = start+sz-1; 
                int maxi = 0;
                //This element is assumed to be the last one to be popped in this range!!
                for(int mid=start;mid<=end;mid++){
                    //As all the in between ones are popped
                    maxi = max( maxi, nums[start-1]*nums[mid]*nums[end+1] + dp[start][mid-1] + dp[mid+1][end] );
                }
                dp[start][end] = maxi;
            }
        }
        return dp[1][n];
    }
};