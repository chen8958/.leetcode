/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    // int maxProfit(vector<int>& prices, int fee) {
    //     vector<int> sell_dp(prices.size(), 0);
    //     vector<int> hold_dp(prices.size(), 0);
    //     hold_dp[0] = -prices[0];
    //     sell_dp[0] = 0;
    //     for(int i = 1; i < prices.size(); i++){
    //         hold_dp[i] = max(hold_dp[i-1], sell_dp[i-1] - prices[i]);
    //         sell_dp[i] = max(hold_dp[i-1] - fee + prices[i], sell_dp[i-1]); 
    //     }
    //     return sell_dp.back();
    // }
    int maxProfit(vector<int>& prices, int fee) {
        int pre_sell_status = 0;
        int pre_hold_status = -prices[0];
        int temp_hold;
        for(int i = 1; i < prices.size(); i++){
            temp_hold = pre_hold_status;
            pre_hold_status = max(pre_hold_status, pre_sell_status - prices[i]);
            pre_sell_status = max(pre_hold_status - fee + prices[i], pre_sell_status); 
        }
        return pre_sell_status;
    
    }
};
// @lc code=end

