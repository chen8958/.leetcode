/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        for(int row = 0; row < obstacleGrid.size(); row++){
            for(int col = 0; col < obstacleGrid[row].size(); col++){
                if(obstacleGrid[row][col]){
                    obstacleGrid[row][col] = 0;
                }else{
                    if(row == 0 && col == 0){
                        obstacleGrid[row][col] = 1;
                    }else{
                        obstacleGrid[row][col] = 
                        ((row == 0) ? 0 : obstacleGrid[row-1][col]) + 
                        ((col == 0) ? 0 : obstacleGrid[row][col-1]);
                    }
                }
            }
        }
        return obstacleGrid.back().back();
    }
};
// @lc code=end

int main(){
    Solution object;
    vector<vector<int>> stones = {{0,0,0},{0,1,0},{0,0,0}};
    auto code = object.uniquePathsWithObstacles(stones);

}