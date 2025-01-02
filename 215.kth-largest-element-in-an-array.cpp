/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// 0' base -> 1' base
// calculate
// 1' base -> 0' base


#include <vector>
#include <stdio.h>
#include <limits.h>
using namespace std;
// @lc code=start

class Solution {
#define GET_PARENT(idx)             (((idx+1)/2)-1)
#define GET_L_CHILD(idx)            (((idx+1)*2)-1)
#define GET_R_CHILD(idx)            (((idx+1)*2))

#define SWAP(value1, value2)        {\
    int temp;\
    temp = value1;\
    value1 = value2;\
    value2 = temp;\
}
public:
    void heapify(vector<int>& nums, int idx){
        if(GET_L_CHILD(idx) >= nums.size()){
                // do nothing
        }else if(GET_R_CHILD(idx) >= nums.size()){
            if(nums[GET_L_CHILD(idx)] > nums[idx]){
                SWAP(nums[idx], nums[GET_L_CHILD(idx)]);
            }
        }else{
            if(nums[GET_L_CHILD(idx)] > nums[GET_R_CHILD(idx)] && nums[GET_L_CHILD(idx)] > nums[idx]){
                SWAP(nums[idx],nums[GET_L_CHILD(idx)]);
                heapify(nums, GET_L_CHILD(idx));
            }else if(nums[GET_R_CHILD(idx)] > nums[idx]){
                SWAP(nums[idx],nums[GET_R_CHILD(idx)]);
                heapify(nums, GET_R_CHILD(idx));
            }else{
                // do nothing
            }
            
        }
    }
    void build_maxheap(vector<int>& nums){
        for(int idx = nums.size()/2; idx >= 0; idx--){
            heapify(nums, idx);
            // if(GET_L_CHILD(idx) >= nums.size()){
            //     continue;
            // }else if(GET_R_CHILD(idx) >= nums.size()){
            //     // only compare left
            //     if(nums[GET_L_CHILD(idx)] > nums[idx]){
            //         SWAP(nums[idx],nums[GET_L_CHILD(idx)]);
            //     }
            // }else{
            //     if(nums[GET_L_CHILD(idx)]>nums[GET_R_CHILD(idx)] && nums[GET_L_CHILD(idx)] > nums[idx]){
            //         SWAP(nums[idx],nums[GET_L_CHILD(idx)]);
            //     }else if(nums[GET_R_CHILD(idx)]>nums[GET_L_CHILD(idx)] && nums[GET_R_CHILD(idx)] > nums[idx]){
            //         SWAP(nums[idx],nums[GET_R_CHILD(idx)]);
            //     }else{
            //         // do nothing
            //     }
            // }
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        build_maxheap(nums);
        for(int i = 0; i < (k-1); i++){
            nums[0] = *nums.rbegin();
            nums.pop_back();
            heapify(nums, 0);
            // nums.assign(nums.begin(), nums.end());
            
        }
        return nums[0];
    }
};
// @lc code=end

int main(){
    Solution object;
    vector<int> nums = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    auto code = object.findKthLargest(nums ,20);
}