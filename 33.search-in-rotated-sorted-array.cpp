/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

#include <vector>
using namespace std;


// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return -1;
        }
        int initial_number = nums[0];
        int r = nums.size()-1, l = 0 ,middle;
        if(target > initial_number){
            // find right of 0
            while(1){
                middle = l + (r - l) / 2;
                while(nums[middle] < initial_number){
                    r = middle - 1;
                    middle = l + (r - l) / 2;
                }

                if(nums[middle] == target){
                    return middle;
                }
                if(r == l){
                    break;
                }

                if(nums[middle] > target){
                    r = middle - 1;
                }else if(nums[middle] < target){
                    l = middle + 1;
                }
            }
        }else if(target < initial_number){
            // find left of end
            while(1){
                middle = l + (r - l) / 2;
                while(nums[middle] > initial_number){
                    l = middle + 1;
                    middle = l + (r - l) / 2;
                }
                if(nums[middle] == target){
                    return middle;
                }
                if(r == l){
                    break;
                }
                if(nums[middle] > target){
                    r = middle - 1;
                }else if(nums[middle] < target){
                    l = middle + 1;
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
    auto code = object.search( nums ,0);

}