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

    struct node{
        pair<int, int> idx;
        // vector<int> nums;
        int sum;
        // bool operator()(const pair<int,int> l_p, const pair<int,int> r_p){
        bool operator()(const node l_node, const node r_node){
            if(l_node.sum > r_node.sum){
                return true;
            }else{
                return false;
            }
        }
        node(){};
        node(const vector<int>& nums1, const vector<int>& nums2, int idx1, int idx2){
            this->idx = make_pair(idx1, idx2);
            // this->nums = {nums1[idx1], nums2[idx2]};
            this->sum = nums1[idx1] + nums2[idx2];
        };
    };
    typedef struct node NODE, *NODE_PTR;

public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<bool>> is_visted_map(nums1.size(), vector<bool>(nums2.size(),false));
        // (num1, num2), sum
        priority_queue<NODE, vector<NODE>, NODE> heap;
        NODE current_node;
        vector<vector<int>> ans;
        heap.push(NODE(nums1,nums2,0,0));
        is_visted_map[0][0] = true;
        for(int i = 0; i < k ; i++){
            current_node = heap.top();
            ans.push_back({nums1[current_node.idx.first],nums2[current_node.idx.second]});
            heap.pop();
            // try to push new node to heap
            // go right and down size
            if(current_node.idx.first + 1 < nums1.size()){
                if(is_visted_map[current_node.idx.first+1][current_node.idx.second] == false){
                    is_visted_map[current_node.idx.first+1][current_node.idx.second] = true;
                    heap.push(NODE(nums1, nums2, current_node.idx.first+1, current_node.idx.second));
                }
            }
            if(current_node.idx.second + 1 < nums2.size()){
                if(is_visted_map[current_node.idx.first][current_node.idx.second+1] == false){
                    is_visted_map[current_node.idx.first][current_node.idx.second+1] = true;
                    heap.push(NODE(nums1, nums2, current_node.idx.first, current_node.idx.second + 1));
                }
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
