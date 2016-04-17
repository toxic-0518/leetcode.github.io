class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int preRest = 0;
        int preSell = INT_MIN;
        int preBuy = -prices[0];
        int sell;
        int rest;
        int buy;
        for(int i = 1; i < prices.size(); i++) {
            rest = max(preRest, preSell);
            sell = preBuy + prices[i];
            buy = max(preBuy, preRest - prices[i]);
            preRest = rest;
            preBuy = buy;
            preSell = sell;
        }
        return max(sell, rest);
    }
};
