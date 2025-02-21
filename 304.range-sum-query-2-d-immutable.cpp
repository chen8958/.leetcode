/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

#include <vector>
using namespace std;

// @lc code=start
class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        dp = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
        for (int row = 0; row < dp.size(); ++row){
            for (int col = 0; col < dp[row].size(); ++col){
                dp[row][col] = (
                    matrix[row][col] +
                    (
                        row == 0 && col == 0 ? 0 : (
                            (row == 0 ? 0 : dp[row-1][col]) +
                            (col == 0 ? 0 : dp[row][col-1]) - 
                            (row != 0 && col != 0 ? dp[row-1][col-1] : 0)
                        )
                    )
                );
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return 
        dp[row2][col2] - 
        (row1 == 0 ? 0 : dp[row1-1][col2]) - 
        (col1 == 0 ? 0 : dp[row2][col1-1]) + 
        (row1 != 0 && col1 != 0 ? dp[row1-1][col1-1] : 0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    NumMatrix object(matrix);
    auto code = object.sumRegion(1,1,2,2);
}
