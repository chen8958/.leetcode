/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

#include <vector>
#include <limits.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int row = 0; row < grid.size(); ++row){
            for(int col = 0; col < grid[row].size(); ++col){
                if (row == 0 && col == 0) continue;
                grid[row][col] =
                                grid[row][col] + 
                                min(
                                    (row == 0 ? INT_MAX : grid[row-1][col]),
                                    (col == 0 ? INT_MAX : grid[row][col-1])
                                    );
            }
        }
        return grid.back().back();
    }
};
// @lc code=end

