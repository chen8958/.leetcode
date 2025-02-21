/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <functional>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>> map(n, vector<vector<TreeNode*>>(n));
        for (int idx = 1; idx <= n ; idx++){
            map[idx-1][idx-1].push_back(new TreeNode(idx));
        }
        function<vector<TreeNode*>(int,int)> helper;
        helper = [&map, &helper](int start, int end){
                if(start > end){
                    return vector<TreeNode*>(1, nullptr);
                }else if(map[start-1][end-1].size()!=0){
                    return map[start-1][end-1];
                }else{
                    for(int root_num = start; root_num <= end; root_num++){
                        for(TreeNode * left_node : helper(start, root_num-1)){
                            for(TreeNode * right_node : helper(root_num+1, end)){
                                map[start-1][end-1].push_back(new TreeNode(root_num, left_node, right_node));
                            }
                        }
                    }
                }
                return map[start-1][end-1];
            };
        return helper(1 , n);
    }

    

};
// @lc code=end

