/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;


// bonus: try to use priority queue;


// @lc code=start
class Solution {
public:
    struct Compare_LESS{
        bool operator()(const pair<int,int> l_p, const pair<int,int> r_p){
            if(l_p.second < r_p.second){
                return true;
            }else{
                return false;
            }
        }
    };
    
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq_map;
        vector<pair<int,int>> heap_container;
        vector<int> ans;
        for(auto n:nums){
            freq_map[n] ++;
        }
        for(auto p:freq_map){
            heap_container.push_back(p);
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare_LESS> heap(heap_container.begin(), heap_container.end());

        for(int i = 0; i < k; i++){
            ans.push_back(heap.top().first);
            heap.pop();
        }
        return ans;
    }
};


// @lc code=end

int main(){
    Solution object;
    vector<int> nums = {1,1,1,2,2,3};
    auto code = object. topKFrequent(nums , 2);
}