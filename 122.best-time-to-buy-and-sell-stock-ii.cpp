/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start

#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int index = 1; index < prices.size(); index++) {
            if(prices[index] > prices[index-1]) profit += (prices[index] - prices[index-1]);
        }
        return profit;
    }
};
// @lc code=end

