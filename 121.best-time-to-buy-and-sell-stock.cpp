/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowprice = prices[0];
        int maxprofit = 0;
        for (int price : prices) {
            if(price < lowprice) {
                lowprice = price;
            }else{
                maxprofit = max(maxprofit, price - lowprice);
            }
        }
        return maxprofit;
    }
};
// @lc code=end

