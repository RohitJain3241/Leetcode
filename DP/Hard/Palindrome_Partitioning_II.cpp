class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        //We need to first see for every combination of i,j that if it is a palindrome or not
        vector<vector<int>> palin(n,vector<int>(n,0));
        //This is for defining 1 length points as palindrome
        for(int i=0;i<n;i++)
            palin[i][i] = 1;
        //This is for 2 length strings
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1])
                palin[i][i+1] = 1;
        }
        
        //This sets the size of the substring
        for(int sz=3;sz<=n;sz++){
            //This sets the starting of the substring
            for(int i=0;i<n-sz+1;i++){
                //If first and last element are equal and insider is also a palindrome
                if(s[i]==s[i+sz-1] && palin[i+1][i+sz-2])
                    palin[i][i+sz-1] = 1;
            }
        }
        
        //This saves number of min cuts after i 
        vector<int> dp(n+1,INT_MAX);
        //As we have single element and null element as a palindrome so min. cuts=0
        dp[n] = dp[n-1] = 0;
        //We will produce the result in backward manner!
        for(int i=n-2;i>=0;i--){
            //If whole substring is a palindrome
            if(palin[i][n-1]){
                dp[i] = 0;
                continue;
            }
            //This is for seeing for palindrome ending with this index
            for(int j=i;j<n-1;j++){
                if(palin[i][j])
                    dp[i] = min( dp[i] , 1 + dp[j+1] );
            }
        }
        
        return dp[0];
    }
};