class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        //We will make 2 variables to save the maximum profit if we don't have anything instack
        //And another variable to save the max. profit if we have something in the array
        int cash=0,hold=-prices[0];
        for(int i=1;i<n;i++){
            //To move from i'th to i+1'th we will update cash
            //Either buy or not buy
            cash = max(hold+prices[i]-fee,cash);
            //Either sell or not sell
            hold = max(hold,cash-prices[i]);
        }
        return cash;
    }
};