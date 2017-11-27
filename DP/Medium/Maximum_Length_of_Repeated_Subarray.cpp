class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n1 = A.size(),n2 = B.size(),m=0;
        //THI saves the max. subarray starting with A[i] and starting with B[j]
        int dp[n1+1][n2+1];
        for(int i=n2;i>=0;i--)
            dp[n1][i] = 0;
        for(int i=n1;i>=0;i--)
            dp[i][n2] = 0;
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                dp[i][j] = 0;
                if(A[i]==B[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
                if(m < dp[i][j])
                    m = dp[i][j];
            }
        }
        return m;
    }
};