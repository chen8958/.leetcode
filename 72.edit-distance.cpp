/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */
#include <string>
#include <functional>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        word1 = string(" ") + word1;
        word2 = string(" ") + word2;
        vector<vector<int>> map(word1.length(), vector<int>(word2.length(), 0));
        for (int row = 0; row < word1.length(); ++row) {
            for (int col = 0; col < word2.length(); ++col) {
                if (row == 0 || col ==0){
                    map[row][col] = max(row, col);
                }else{
                    map[row][col] = (word1[row] == word2[col] ?
                    map[row-1][col-1] :
                    1 + min({map[row-1][col], map[row][col-1], map[row-1][col-1]})
                    );
                }
            }
        }
        return map.back().back();
    }
};

// @lc code=end

int main(){
    Solution object;
    object.minDistance(
        "zoologicoarchaeologist",
        "zoogeologist");
}