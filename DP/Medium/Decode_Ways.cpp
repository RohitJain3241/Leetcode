class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int dp[n+1];
        dp[n] = 1;
        if(n==0)
            return 0;
        //0 case!
        for(int i=n-1;i>=0;i--){
            dp[i]=0;
            if(s[i]!=48){
                dp[i] += dp[i+1];
                if(i+2<=n && 10*(s[i]-48)+(s[i+1]-48)<=26)
                    dp[i]+=dp[i+2];
                        }
        }
        return dp[0];
    }
};