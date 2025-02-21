/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currmax = 0;
        int currmin = 0;
        int temp_max;
        int prodmax = INT_MIN;
        for(int num:nums){
            if (currmax == 0){
                currmax = num;
                currmin = num;
            }else{
                temp_max = currmax;
                currmax = max({num * currmax, num * currmin, num});
                currmin = min({num * temp_max, num * currmin, num});
                
            }
            if(currmax > prodmax)prodmax = currmax;
        }
        return prodmax;
        
    }
};
// @lc code=end

