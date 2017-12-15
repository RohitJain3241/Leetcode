class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(),m = word2.length();
        if(n==0 || m==0)
            return max(n,m);
        //This saves the edit distance for i onwards and j onwards words
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //Edit distance of 2 voids is equal to 0
        dp[n][m] = 0;
        //This is for recurrence of void 1st or void 2nd
        for(int i=n-1;i>=0;i--)
            dp[i][m] = n-i;
        for(int i=m-1;i>=0;i--)
            dp[n][i] = m-i;
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(word1[i] != word2[j])
                    dp[i][j] = 1 + min( dp[i+1][j] , min( dp[i][j+1] , dp[i+1][j+1] ) );
                else
                    dp[i][j] = dp[i+1][j+1];
            }
        }
        return dp[0][0];
    }
};