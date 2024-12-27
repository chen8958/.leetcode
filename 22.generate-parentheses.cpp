/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    void recursive_draw_parenthesis(int n, int r, int l, string current_string, vector<string> &temp){
        if((l+1)==n && r==n){
            temp.push_back(current_string + ')');
        }else{
            if(r < n){
                recursive_draw_parenthesis(n, r+1, l, current_string + '(', temp);
            }
            if(l < r){
                recursive_draw_parenthesis(n, r, l+1, current_string + ')', temp);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> temp;
        recursive_draw_parenthesis(n, 0, 0, "", temp);
        return temp;
    }
};
// @lc code=end

int main(){
    Solution object;
    auto vec = object.generateParenthesis(3);
    for(auto s:vec){
        printf("%s",s);
    }
}