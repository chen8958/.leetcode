/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> hold_dp(prices.size());
        vector<int> sell_dp(prices.size());
        hold_dp[0] = -prices[0];
        sell_dp[0] = 0;
        for(int index = 1; index < prices.size(); index++){
            hold_dp[index] = (max(hold_dp[index-1], (index == 1? sell_dp[index-1] : sell_dp[index-2]) - prices[index]));
            sell_dp[index] = max(hold_dp[index-1] + prices[index], sell_dp[index-1]);
        }
        return sell_dp.back();
    }
};
// @lc code=end

