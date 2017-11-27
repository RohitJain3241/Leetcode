class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+100000,-1);
        dp[0] = 0;
        dp[1] = 1;
        long long pow2[40];
        for(int i=0;i<40;i++) pow2[i] = pow(2,i);
        //This loop is for selecting the power of 2
        for(int i=1;;i++){
            dp[pow2[i]] = 1;
            if(dp[num]!=-1)
                break;
            //We iterate until we reach the upper power of 2
            for(int j=pow2[i]+1;j<pow2[i+1];j++){
                dp[j] = 1 + dp[j-pow2[i]];
                if(dp[num]!=-1)
                    break;
            }
        }
        vector<int>::const_iterator first = dp.begin();
        vector<int>::const_iterator last = dp.begin() + num + 1;
        vector<int> newVec(first, last);
        return newVec;
    }
};