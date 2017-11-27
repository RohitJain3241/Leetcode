class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(),j,mini=-2147483648;
        //all negative test case
        for(j=0;j<n;j++){
            if(nums[j]>=0)
                break;
            if(nums[j]>mini)
                mini = nums[j];
        }
        if(j==n)
            return mini;
        int maxi = 0,conti = 0;
        //We will mantain a contiguous sum and a max sum
        for(int i=0;i<n;i++){
            conti = conti + nums[i];
            if(conti < 0)
                conti = 0;
            else if(conti> maxi)
                maxi = conti;
        }
        return maxi;
    }
};