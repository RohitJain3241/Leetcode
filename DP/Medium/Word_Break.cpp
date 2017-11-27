class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        //Thi save whether substring behind i is good 
        bool dp[n+1];
        dp[n] = true;
        dp[n-1] = ( find( wordDict.begin(), wordDict.end(), s.substr(n-1,1) )!= wordDict.end()  )?   true:false;
        if(n==0)
            return true;
        //Algo : take different length substring from s and see if both sides occur or not
        //Recursive function gave us TLE
        //If we find the first i elements to be in dict
        for(int i=n-2;i>=0;i--){
            dp[i] = false;
            for(int j=i+1;j<=n;j++){
                if( find( wordDict.begin(), wordDict.end(), s.substr(i,j-i) )!= wordDict.end()  && dp[j]==true )
                    dp[i] = true;
            }
        }
        return dp[0];
    }
};