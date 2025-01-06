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

#define PARENT(idx)         (((idx+1)/2)-1)
#define L_CHILD(idx)        (((idx+1)*2)-1)
#define R_CHILD(idx)        ((idx+1)*2)
    // pair: (key_number, frequency)
    bool compare_large(pair<int,int> l_p, pair<int,int> r_p){
        if(l_p.second > r_p.second){
            return true;
        }else{
            return false;
        }
    }
    void heapify(vector<pair<int,int>>& heap_container, int idx){

        if(L_CHILD(idx) >= heap_container.size()){
            
        }else if(R_CHILD(idx) >= heap_container.size()){
            if(compare_large(heap_container[L_CHILD(idx)], heap_container[idx])){
                swap(heap_container[L_CHILD(idx)], heap_container[idx]);
            }
        }else{
            if(compare_large(heap_container[L_CHILD(idx)], heap_container[idx]) && compare_large(heap_container[L_CHILD(idx)], heap_container[R_CHILD(idx)])){
                swap(heap_container[L_CHILD(idx)], heap_container[idx]);
                heapify(heap_container, L_CHILD(idx));
            }else if(compare_large(heap_container[R_CHILD(idx)], heap_container[idx])){
                swap(heap_container[R_CHILD(idx)], heap_container[idx]);
                heapify(heap_container, R_CHILD(idx));
            }else{
                // do nothing
            }

        }
        

    }
    void build_heap(vector<pair<int,int>>& heap_container){
        for(int idx = heap_container.size()/2; idx >= 0; idx--){
            heapify(heap_container, idx);
        }
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq_map;
        vector<pair<int,int>> heap_container;
        vector<int> ans;
        // O(n)
        for(auto n:nums){
            freq_map[n] ++;
        }
        for(auto p:freq_map){
            heap_container.push_back(p);
        }
        build_heap(heap_container);
        // contruct heap O(n)
        // pop heap klog(n)
        for(int i = 0; i < k; i++){
            swap(*heap_container.begin(), *(heap_container.rbegin()));
            ans.push_back((*heap_container.rbegin()).first);
            heap_container.pop_back();
            heapify(heap_container, 0U);
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