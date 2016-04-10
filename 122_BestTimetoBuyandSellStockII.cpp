class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int profit = 0;
        bool sale = false;
        int i = 0;
        while(i < prices.size()) {
            if(!sale) {
                while((i < prices.size() - 1) && (prices[i] > prices[i + 1])) i++;
                if(i < prices.size() - 1) {
                    profit -= prices[i];
                    sale = true;
                }
            }
            else {
                while((i < prices.size() - 1) && (prices[i] < prices[i + 1])) i++;
                if(i < prices.size()) {
                    profit += prices[i];
                    sale = false;
                }
            }
            i++;
        }
        return profit;
    }
};
