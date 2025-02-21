/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size()+s2.size() != s3.size()) return false;
        s1 = string(" ") + s1;
        s2 = string(" ") + s2;
        vector<vector<bool>> map(s1.size(), vector<bool>(s2.size(),false));
        for(int row = 0; row < s1.size(); ++row){
            for(int col = 0; col < s2.size(); ++col){
                if (row == 0 && col == 0){
                    map[row][col] = true;
                }else if(
                    (row == 0? false : map[row-1][col])
                ){
                    if (s1[row] == s3[col + row -1]) map[row][col] = true;
                }else if(
                    (col == 0? false : map[row][col-1])
                ){
                    if (s2[col] == s3[col + row -1]) map[row][col] = true;
                }
            }
        }
        return map.back().back();
    }
};
// @lc code=end
int main(){
    Solution object;
    auto code = object.isInterleave("ab","bc","bbac");
}
