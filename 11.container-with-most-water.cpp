/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
#include <vector>

// @lc code=start
class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max = 0;
        int temp;
        int size = height.size() - 1;
        auto it = height.begin();
        auto r_it = height.end() - 1;
        while(it != r_it)
        {
            temp = std::min(*it, *r_it) * size;
            if ( temp > max){
                max = temp;
            }
            if(*it < *r_it){
                it++;
            }else{
                r_it--;
            }
            size --;
        }
        return max;
    }
};
// @lc code=end

int main(){
    Solution object;
    std::vector<int>height = {1,8,6,2,5,4,8,3,7};
    int value = object.maxArea(height);
}