class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> res;
        //This save the sum of every k elements starting with 'start'
        vector<int> summer(n-k+1,0);
        //Generating summer[0]
        for(int i=0;i<k;i++){
            summer[0] += nums[i];
        }
        //This is for generating summer array!
        for(int start=1;start<n-k+1;start++)
            summer[start] = summer[start-1] - nums[start-1] + nums[start+k-1];
        
        //This saves best sum after i'th element and with j overlapping parts
        int dp[n-k+2][4];
        
        //We have max_sum=0 for all j=0
        for(int i=0;i<n-k+2;i++)
            dp[i][0] = 0;
        
        //For after the last element
        dp[n-k+1][1] = dp[n-k+1][2] = dp[n-k+1][3] = INT_MIN;
        
        for(int i=n-k;i>=0;i--){
            //This is for the separate 3 parts that we need
            for(int j=1;j<4;j++){
                dp[i][j] = dp[i+1][j];
                //This condition is necessary as when n==1 we don't need to see further.
                if(j==1)
                    dp[i][j] = max( dp[i][j], summer[i]);
                else if(i+k<n-k+2)
                    //We either choose between choosing this element or not choosing it and seeing for the best beyond i+1
                    dp[i][j] = max( dp[i][j], summer[i] + dp[i+k][j-1] );
            }
        }
        
        //Now we create the backtracking part to obtain the vector of indices
        int z=3,ss=0;
        while(1){
            //For n==1 we need to check for different condition.
            if(z==1){
                for(int i=ss;i<n-k+2;i++){
                    if(dp[i][z]==summer[i]){
                        res.push_back(i);
                        z--;
                        break;
                    }
                }
                return res;
            }
            //This condition is added first so as to give the result in lexicographic order
            if( ss+k < n-k+2 && dp[ss][z] == summer[ss] + dp[ss+k][z-1] ){
                res.push_back(ss);
                ss += k;
                z--;
            }
            else
                ss++;
        }
    }
};