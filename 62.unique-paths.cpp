/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> map(m, vector<int>(n));
        for(int row = 0; row < m; row ++){
            for(int col = 0; col < n; col++){
                if(row == 0 || col == 0){
                    map[row][col] = 1;
                }else{
                    map[row][col] = map[row-1][col] + map[row][col-1];
                }
            }
        }
        return map[m-1][n-1];
    }
};
// @lc code=end

int main(){
    Solution object;
    
    auto code = object.uniquePaths(3 ,4);

}