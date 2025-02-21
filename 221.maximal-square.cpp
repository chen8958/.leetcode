/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int max = 0;
        vector<vector<int>> map(matrix.size(), vector<int>(matrix[0].size()));
        for (int row = 0; row < matrix.size(); ++row) {
            for (int col = 0; col < matrix[row].size(); ++col) {
                if (matrix[row][col] == '0'){
                    map[row][col] = 0;
                }else{
                    map[row][col] = ( (row == 0) || (col == 0) ? 1 : 1 + min(
                        {
                        map[row-1][col],
                        map[row][col-1],
                        map[row-1][col-1]
                        }
                    ) );
                    if(map[row][col] > max) max = map[row][col];
                }
            }
        }
        return max*max;
    }
};
// @lc code=end

int main(){
    Solution object;
    vector<vector<char>> nums = 
    {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    auto code = object.maximalSquare(nums);
}
