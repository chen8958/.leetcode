/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


class Solution {
public:
    string frequencySort(string s) {
        // binary tree map
        // word to freq
        string ans;
        vector<pair<char, int>> sort_vec_container;
        unordered_map<char, int> freq_table;
        auto sort_freq = [](pair<char,int> p1,pair<char,int> p2){
            return p2.second < p1.second;
        };
        for(auto c : s){
            freq_table[c] = freq_table[c] + 1;
        }
        for(auto p : freq_table){
            sort_vec_container.push_back(p);
        }
        sort<vector<pair<char,int>>::iterator, decltype(sort_freq)>(sort_vec_container.begin(),sort_vec_container.end(),sort_freq);
        for(pair<char, int> p : sort_vec_container){
            for(int times = 0; times < p.second; times++){
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution object;
    string s = "raaeaedere";
    auto code = object.frequencySort(s);

}