class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxprofit = 0;
        int low = prices[0];
        for (int i =0; i<n; i++)
        {
            maxprofit = max(maxprofit, prices[i]-low);
            low = min(low, prices[i]);
        }
        return maxprofit;
    }
};
