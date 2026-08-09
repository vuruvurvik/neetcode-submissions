class Solution {
    int fun(int idx, int buy, vector<int>& prices,
            vector<vector<int>>& dp) {

        if (idx == prices.size())
            return 0;

        if (dp[idx][buy] != -1)
            return dp[idx][buy];

        int profit;

        if (buy) {
            profit = max(
                -prices[idx] + fun(idx + 1, 0, prices, dp),
                fun(idx + 1, 1, prices, dp)
            );
        }
        else {
            profit = max(
                prices[idx] + fun(idx + 1, 1, prices, dp),
                fun(idx + 1, 0, prices, dp)
            );
        }

        return dp[idx][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return fun(0, 1, prices, dp);
    }
};