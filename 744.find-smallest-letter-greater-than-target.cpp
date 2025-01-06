/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        for(auto c:letters){
            if(c > target){
                ans = c;
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

