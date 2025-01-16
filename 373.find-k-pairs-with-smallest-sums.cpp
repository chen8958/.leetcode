/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */
#include <vector>
#include <queue>


using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int x,y;
        auto compare_lambda_function = [& nums1, & nums2](pair<int, int>p1, pair<int,int> p2){
            return (nums1[p1.first]+nums2[p1.second]) > (nums1[p2.first] + nums2[p2.second]);
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(compare_lambda_function)> pq(compare_lambda_function);
        int queue1_size = nums1.size();
        int queue2_size = nums2.size();
        vector<vector<int>> ans;

        for(int i = 0; i < min(queue1_size, k); i++){
            pq.push(pair<int,int>{i,0});
        }
        while(k--){
            x = pq.top().first;
            y = pq.top().second;
            ans.push_back({nums1[x] ,nums2[y]});
            pq.pop();
            if((y+1) < queue2_size){
                pq.push(pair<int,int>{x, y+1});
            }
        }
        return ans;
    }
};
// @lc code=end
int main(){
    Solution object;
    vector<int> nums1 = {1,2,4,5,6};
    vector<int> nums2 = {3,5,7,9};
    auto code = object.kSmallestPairs(nums1, nums2 , 20);
}
