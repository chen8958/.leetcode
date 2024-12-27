/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // consider size == 0 case
    vector<string> recursive_enter_word(string input, unordered_map<char, string>digits_map)
    {
        vector<string> temp;
        if(input.size()>1){
            vector<string> previous_temp = recursive_enter_word(string(input.begin(), input.end()-1), digits_map);
            for(auto s:previous_temp){
                for(auto w:digits_map[*(input.rbegin())]){
                    temp.push_back(s + w);
                }
            }
        }else if(input.size()!=0){
            for(auto w:digits_map[input[0]]){
                temp.push_back(string(1, w));
            }
        }
        return temp;
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string>digits_map;
        digits_map['2'] = "abc";
        digits_map['3'] = "def";
        digits_map['4'] = "ghi";
        digits_map['5'] = "jkl";
        digits_map['6'] = "mno";
        digits_map['7'] = "pqrs";
        digits_map['8'] = "tuv";
        digits_map['9'] = "wxyz";
        vector<string> ans = recursive_enter_word(digits, digits_map);
        return ans;
    }
};
// @lc code=end
int main(){
    Solution object;
    auto vec = object.letterCombinations("23");
    for(auto s:vec){
        printf("%s",s);
    }
}