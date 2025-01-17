/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


// @lc code=start
class Solution {
public:
    bool compare_string(string s1, string s2){
        for(int i = 0; i < min(s1.size(), s2.size()); i++){
            if(s1[i] < s2[i]){
                return true;
            }else if(s1[i] > s2[i]){
                return false;
            }
        }
        return s1.size()<s2.size();
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> string_freq_map;
        vector<string> ans;
        vector<pair<string, int>> sort_freq_container;
        // this is means class function
        auto sort_pair_function = [this](pair<string, int> p1, pair<string, int>p2){
            if (p2.second == p1.second){
                return compare_string(p1.first, p2.first);
            }
            return p2.second < p1.second;
        };
        for (string s : words){
            string_freq_map[s]++;
        }
        for(pair p : string_freq_map){
            sort_freq_container.push_back(p);
        }
        sort<
            vector<pair<string, int>>::iterator,
            decltype(sort_pair_function)
            >(sort_freq_container.begin(), sort_freq_container.end(), sort_pair_function);
        
        for (int i = 0; i<k;i++){
            ans.push_back(sort_freq_container[i].first);
        }
        return ans;
    }
};
// @lc code=end

