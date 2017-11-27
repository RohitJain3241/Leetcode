class Solution {
    
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];});
        int n = pairs.size();
        //This will keep the longest chain uptil i
        int dp[n];
        //This is the last index of the array
        for(int i=0;i<n;i++){
            if(i==0){
                dp[0] = 1;
                continue;   
            }
            dp[i] = 1;
            for(int j=i-1;j>=0;j--){
                if(pairs[j][1]<pairs[i][0])
                    dp[i] = max(dp[i],1+dp[j]);
            }
        }
        return dp[n-1];
    }
};