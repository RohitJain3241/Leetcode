//n=1 case
class Solution {
public:
    int getMoneyAmount(int n) {
        //The first index is starting and 2nd is end
        int dp[n+1][n+1];
        //dp[start][end] = min(all solutions between them with 2 halves maximum)
        //This is for the single element case.
        for(int i=1;i<=n;i++)
            dp[i][i] = 0;
        //This is for the 2 element case!
        for(int i=1;i<n;i++)
            dp[i][i+1] = i;
        //
        for(int siz=3;siz<=n;siz++){
            for(int start=1;start<=n-siz+1;start++){
                dp[start][start+siz-1] = 12345678;
                //We will go from start to start+siz-1
                for(int k=start+1;k<=start+siz-2;k++)
                    //using minimax approach!
                    dp[start][start+siz-1] = min( dp[start][start+siz-1] , k + max( dp[start][k-1], dp[k+1][start+siz-1] ) );
            }
        }
        return dp[1][n];
    }
};
