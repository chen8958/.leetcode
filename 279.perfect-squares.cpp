/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
#include <vector>
#include <math.h>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        // cast or tranform?
        dp[0] = 0;
        int maxSquares = (int)sqrt(n);
        for(int i = 1; i<= maxSquares; i++){
            int val = i*i;
            for(int index = val; index <= n; index++){
                dp[index] = min(dp[index],dp[index - val] + 1);
            }
        }
        return dp.back();
    }
};
// @lc code=end

int main(){
    Solution object;
    auto code = object.numSquares(12);
}
