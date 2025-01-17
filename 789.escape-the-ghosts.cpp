/*
 * @lc app=leetcode id=789 lang=cpp
 *
 * [789] Escape The Ghosts
 */
#include <vector>
#include <stdlib.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int calculate_distance(const vector<int> &pos1, const vector<int> &pos2){
        return abs(pos1[0]-pos2[0]) + abs(pos1[1]-pos2[1]);
    }
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int target_distance = abs(target[0])+abs(target[1]);
        for (const vector<int>& ghost: ghosts) {
            if(target_distance >= calculate_distance(ghost, target)){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

