/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int global_max = 0;
        vector<int> dp(nums.size(), 1);
        function<void(int)> find_max;
        find_max = [&nums, &dp, &global_max](int index){
            // can use binary search
            // dp[index] =max(dp[index], 1 + *max_element(dp.begin(), dp.begin() + index - 1));
            for(int i = 0; i < index; i++){
                if (nums[index] > nums[i]){
                    dp[index] = max(dp[index], dp[i] + 1);
                }else{
                    continue;
                }
            }
            if(dp[index] > global_max) global_max = dp[index]; 
        };
        for(int index = 1; index < nums.size(); index++) find_max(index);
        return global_max;
    }
};
// @lc code=end

