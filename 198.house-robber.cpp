/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

#include <vector>
#include <functional>
#include <limits.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        function<int(int)> get_sub_array_max;
        vector<int> note(nums.size(), INT_MIN);
        get_sub_array_max = [&nums, &get_sub_array_max, &note](int index){
            if (note[index]!=INT_MIN) return note[index];
            if (index == 1){
                note[index] = max(nums[0] ,nums[1]);
            }else if(index == 0){
                note[index] = nums[0];
            }else{
                note[index] = max(
                    nums[index] + get_sub_array_max(index - 2),
                    get_sub_array_max(index - 1)
                );
            }
            return note[index];
        };
        return get_sub_array_max(nums.size()-1);
    }
};
// @lc code=end

