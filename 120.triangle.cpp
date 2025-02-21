/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int level = triangle.size()-2; level >= 0; level--){
            for(int index = 0; index < triangle[level].size();index++){
                triangle[level][index] = triangle[level][index] + min(
                    triangle[level+1][index],
                    triangle[level+1][index+1]
                    );
            }
        }
        return triangle[0][0];
    }
};
// @lc code=end

