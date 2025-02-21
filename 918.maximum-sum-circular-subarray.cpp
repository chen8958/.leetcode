/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */
#include <vector>
#include <limits.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        vector<int> extend_circular_buffer;
        extend_circular_buffer.insert(extend_circular_buffer.end(), nums.begin(), nums.end());
        extend_circular_buffer.insert(extend_circular_buffer.end(), nums.begin(), nums.end());
        int max_sum = INT_MIN;
        int current_sum = INT_MIN;
        int num;
        int subarray_size = 0;
        for(int i = 0; i < extend_circular_buffer.size(); i++){
            num = extend_circular_buffer[i];
            if((current_sum + num) <= num){
                current_sum = num;
                subarray_size = 1;
            }else{
                if(subarray_size == nums.size()){
                    current_sum -= extend_circular_buffer[i - nums.size()];
                    current_sum += num;
                }else{
                    current_sum += num;
                    subarray_size ++;
                }
            }
            if(current_sum > max_sum)max_sum=current_sum;
        }
        return max_sum;
    }
};
// @lc code=end
int main(){
    Solution object;
    vector<int> buffer = {5,-3,5};
    auto code = object.maxSubarraySumCircular(buffer);

}
