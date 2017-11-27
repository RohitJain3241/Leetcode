class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        //Longest palindromic with start=i,end=j
        int dp[n][n];
        
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int size=2;size<=n;size++){
            //This sets the starting index!
            for(int i=0;i<=n-size;i++){
                if(s[i]==s[size+i-1]){
                    if(size!=2)
                        dp[i][i+size-1] = 2 + dp[i+1][size+i-2];
                    else
                        dp[i][i+size-1] = 2;
                }
                else{
                    dp[i][i+size-1] = max(dp[i][i+size-2],dp[i+1][i+size-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};