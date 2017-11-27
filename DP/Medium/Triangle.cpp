class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int dp[n],dp1[n];
        for(int i=0;i<n;i++) dp[i] = triangle[n-1][i];
        for(int i=n-2;i>=0;i--){
            if((n-i)%2==0)
                for(int j=0;j<=i;j++){
                    dp1[j] = triangle[i][j]+min(dp[j],dp[j+1]);    
                }
            else
                for(int j=0;j<=i;j++){
                    dp[j] = triangle[i][j]+min(dp1[j],dp1[j+1]);
                }
        }
        if(n%2!=0)
            return dp[0];
        else 
            return dp1[0];
    }
};