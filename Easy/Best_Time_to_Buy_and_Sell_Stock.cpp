class Solution {
public:
    //This is O(n^1) algorithm!
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0)
            return 0;
        int mm=0,mini=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]<mini)
                mini = prices[i];
            else{
                if(mm < prices[i]-mini)
                    mm = prices[i]-mini;
            }
        }
        return mm;
    }
};