class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        //This saves the longest length till i,j
        int dp[s1.length()+1][s2.length()+1];
        dp[s1.length()][s2.length()] = 0;
        for(int i=s1.length()-1;i>=0;i--)
            dp[i][s2.length()] = s1[i]+dp[i+1][s2.length()];
        for(int i=s2.length()-1;i>=0;i--)
            dp[s1.length()][i] = s2[i]+dp[s1.length()][i+1];
        for(int i=s1.length()-1;i>=0;i--){
            for(int j=s2.length()-1;j>=0;j--){
                if(s2[j]==s1[i])
                    dp[i][j] = dp[i+1][j+1];
                else
                    dp[i][j] = min(s1[i]+dp[i+1][j], s2[j]+dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};