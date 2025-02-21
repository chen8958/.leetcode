/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
// @lc code=start
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        vector<int> dp_left(prices.size(),0);
        vector<int> dp_right(prices.size(),0);
        int min_price = prices[0];
        for (int i = 1; i < dp_left.size(); i++) {
            if(prices[i] < min_price) min_price = prices[i];
            dp_left[i] = max(dp_left[i-1], prices[i]-min_price);
        }
        int max_price = prices.back();
        for (int i = dp_right.size() - 1 -1; i >= 0; i--){
            if(prices[i] > max_price) max_price = prices[i];
            dp_right[i] = max(dp_right[i+1], max_price - prices[i]);
        }
        int max_profit = 0;
        for(int mid = 0; mid < prices.size(); mid++){
            max_profit = max(max_profit, dp_left[mid] + (
                mid + 1 == prices.size()? 0 : dp_right[mid + 1]
                ));
        }
        return max_profit;

    }

    // int maxProfit(vector<int>& prices) {
    //     vector<vector<int>> dp(prices.size(),vector<int>(prices.size(), -1));
    //     function<int(int, int)> fill_dp;
    //     int max_profit = 0;
    //     for(int i = 0; i < prices.size(); i++)dp[i][i] = 0;
    //     fill_dp = [&prices, &dp, &fill_dp](int start, int end){ 
    //         if (dp[start][end]!=-1) return dp[start][end];
    //         return dp[start][end] = max({
    //             fill_dp(start, end-1),
    //             fill_dp(start+1, end),
    //             prices[end] - prices[start]
    //         });
    //     };
    //     fill_dp(0, prices.size()-1);
    //     for(int mid = 0; mid < prices.size(); mid++){
    //         max_profit = max(max_profit, dp[0][mid] + (
    //             mid + 1 == prices.size() ? 0 : dp[mid + 1].back()
    //             ));
    //     }
    //     return max_profit;
    // }
};
// @lc code=end

int main(){
    Solution object;
    vector<int> nums = {3,3,5,0,0,3,1,4};
    auto code = object.maxProfit(nums);

}