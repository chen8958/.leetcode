/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, -1);
        for(int coin_value:coins){
            for(int total_value = coin_value; total_value < dp.size(); total_value++){
                if(total_value == coin_value){
                    dp[total_value] = 1;
                }else{
                    if(dp[total_value - coin_value] != -1){
                        dp[total_value] = dp[total_value - coin_value] + 1;
                    }
                }
            }
        }
        return dp.back();
    }
};
// @lc code=end

