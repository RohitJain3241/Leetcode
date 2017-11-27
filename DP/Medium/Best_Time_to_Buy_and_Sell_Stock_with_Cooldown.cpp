class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1 || n==0)
            return 0;
        //cash is the max profit with nothing in hand
        //hold is the max profit with something in hand
        int cash1 = 0,hold = -prices[0],temp,cash2 = 0;
        for(int i=1;i<n;i++){
            temp = cash1;
            cash1 = max(cash1,hold+prices[i]);
            hold = max(hold,cash2-prices[i]);
            cash2 = temp;
        }
        return cash1;
    }
};