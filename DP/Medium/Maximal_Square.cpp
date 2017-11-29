class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m==0)
            return 0;
        int n = matrix[0].size();
        if(n==0)
            return 0;
        //Step 1: We need to save for each index (i,j) 
        //        number of consecutive previous 1's for rows and columns ending in that index
        int rows[m][n],cols[m][n];
        for(int i=0;i<m;i++){
            rows[i][0] = (matrix[i][0]=='1')?  1:0;
            for(int j=1;j<n;j++){
                rows[i][j] = 0;
                if(matrix[i][j]!='0')
                    rows[i][j] = rows[i][j-1]+1;
            }
        }
        for(int i=0;i<n;i++){
            cols[0][i] = (matrix[0][i]=='1')?  1:0;
            for(int j=1;j<m;j++){
                cols[j][i] = 0;
                if(matrix[j][i]!='0')
                    cols[j][i] = cols[j-1][i]+1;
            }
        }
        //This saves the size of square matrix ending in (i,j)
        int dp[m][n];
        int maxsz=0;
        //For the first row:-
        for(int i=0;i<n;i++){
            dp[0][i] = 0;
            if(matrix[0][i]=='1'){
                dp[0][i] = 1;
                maxsz=1;
            }
        }
        //For the first column:-
        for(int i=0;i<m;i++){
            dp[i][0] = 0;
            if(matrix[i][0]=='1'){
                dp[i][0] = 1;
                maxsz=1;
            }
        }
        //Step 2:Main algorithm
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = 0;
                //If the element is 0, then max. square size ending at (i,j) is surely of 0!
                if(matrix[i][j]=='0')
                    continue;
                //Else choose between least of these
                else
                    dp[i][j] = min( 1 + dp[i-1][j-1], min(rows[i][j], cols[i][j]) );
                //This is for keeping track of max. so far.
                if(maxsz < dp[i][j])
                    maxsz = dp[i][j];
            }
        }
        return maxsz*maxsz;
    }
};