/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

#include <vector>
#include <functional>
using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        function<int(int,int)> liner_rob;
        liner_rob = [&nums](int start, int end){
            int rob = 0, notrob = 0;
            for(int index = start; index < end; index++){
                int prenotrob = notrob;
                int prerob = rob;
                rob = prenotrob + nums[index];
                notrob = max(prenotrob, prerob);
            }
            return max(rob, notrob);
        };
        if (nums.size() == 1){
            return nums[0];
        }else{
            return max(liner_rob(0,nums.size()-1), liner_rob(1,nums.size()));
        }
    }
};
// @lc code=end

int main(){
    Solution object;
    vector<int> nums = {1,2,3,1};
    auto code = object.rob(nums);
}