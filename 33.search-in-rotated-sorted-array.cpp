/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

#include <vector>
using namespace std;


// @lc code=start
class Solution {
#define GET_MIDDLE(r,l) (l == (r + l)/2)?(r):((r + l)/2)
public:
    int search(vector<int>& nums, int target) {
        int initial_number = nums[0];
        int r = nums.size(), l = 0 ,middle;
        if(target > initial_number){
            // find right of 0
            while(r!=l){
                middle = GET_MIDDLE(r,l);
                while(nums[middle] < initial_number){
                    r = middle;
                    middle = GET_MIDDLE(r,l);
                }
                if(nums[middle] > target){
                    r = middle;
                }else if(nums[middle] < target){
                    l = middle;
                }else{
                    return middle;
                }
            }
        }else if(target < initial_number){
            // find left of end
            while(r!=l){
                middle = GET_MIDDLE(r,l);
                while(nums[middle] > initial_number){
                    l = middle;
                    middle = GET_MIDDLE(r,l);
                }
                if(nums[middle] > target){
                    r = middle;
                }else if(nums[middle] < target){
                    l = middle;
                }else{
                    return middle;
                }
            }
        }else{
            return 0;
        }
        //did not find target
        return -1;

    }
};
// @lc code=end

int main(){
    Solution object;
    vector<int> nums = {4,5,6,7,0,1,2};
    auto code = object.search( nums ,3);

}