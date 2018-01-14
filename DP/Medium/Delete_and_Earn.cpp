class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();   //0 case and 1 case
        if(n==0) return 0;
        //Firstly we sort the numbers
        sort(nums.begin(),nums.end());
        //Now we will count the occurence of each number
        vector<pair<int,int> > cc;
        for(int i=0;i<n;){
            int no = nums[i],counter=0,j=i;
            for(;j<n;j++){  
                if(nums[j]==no) counter++;
                else break;
            }
            cc.push_back(make_pair(no,counter));
            i = j;
        }
        vector<int> dp(cc.size()+1);
        dp[0] = 0; dp[1] = cc[0].first*cc[0].second;
        for(int i=2;i<dp.size();i++){
            if(cc[i-1].first-cc[i-2].first==1)
                dp[i] = max( cc[i-1].first*cc[i-1].second + dp[i-2] , dp[i-1] );
            else
                dp[i] = cc[i-1].first*cc[i-1].second + dp[i-1];
            }
        return dp[dp.size()-1];
    }
};