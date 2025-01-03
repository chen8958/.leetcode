/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 */

#include "vector"
#include "queue"
#include <functional>
#include "algorithm"
using namespace std;

// @lc code=start
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> current_idx(primes.size() ,0);
        vector<int> current_value(primes);
        vector<int> dp_array(n);
        dp_array[0] = 1;
        for(int i = 1; i < n; i++){
            dp_array[i] = *(min_element(current_value.begin(), current_value.end()));
            for(int idx = 0; idx < primes.size(); idx++){
                if(current_value[idx] == dp_array[i]){
                    current_idx[idx]++;
                    if(dp_array[current_idx[idx]] > (INT_MAX/primes[idx])){
                        current_value[idx] = INT_MAX;
                    }else{
                        current_value[idx] = dp_array[current_idx[idx]] * primes[idx];
                    }
                    
                }
            }
        }
        return *dp_array.rbegin();
    }
};
// @lc code=end

int main(){
    Solution object;
    vector<int> nums = {2,997};
    auto code = object.nthSuperUglyNumber(67 ,nums);
}