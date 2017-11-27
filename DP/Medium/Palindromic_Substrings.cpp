class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(),cnt=0;
        if(n==0)
            return 0;
        //This saves whether string starting at i and ending at j is palindrome or not
        int dp[n][n];
        //This is for length = 1
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
            cnt++;
        }
        //This is for length=2
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = 1;
                cnt++;
            }
            else
                dp[i][i+1] = 0;
        }
        for(int sz=3;sz<=n;sz++){
            for(int i=0;i<=n-sz;i++){
                if(s[i]==s[i+sz-1] && dp[i+1][i+sz-2]==1){
                    dp[i][i+sz-1] = 1;
                    cnt++;
                }
                else
                    dp[i][i+sz-1] = 0;
            }
        }
        return cnt;
    }
};