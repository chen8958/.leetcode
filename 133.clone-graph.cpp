/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node copied_root;
    Node* cloneGraph(Node* node) {
        Node* current_copied_node_ptr;
        Node* current_node_ptr;
        vector<bool> isfinished_map(101, false);
        vector<Node*> node_bank(101, nullptr);
        // original and copied
        queue<pair<Node*, Node*>> node_queue;
        node_queue.push({node, &copied_root});
        while(node_queue.size()!=0) {
            auto [current_node_ptr, current_copied_node_ptr] = node_queue.front();
            node_queue.pop();
            for(Node* child_ptr : current_node_ptr->neighbors){
                //if not finished yet
                if (isfinished_map[child_ptr->val] == false){
                    if(node_bank[child_ptr->val] == nullptr){
                        node_bank[child_ptr->val] = new Node(child_ptr->val);
                    }
                    Node* new_child_ptr = node_bank[child_ptr->val];
                    current_copied_node_ptr->neighbors.push_back(new_child_ptr);
                    new_child_ptr->neighbors.push_back(current_copied_node_ptr);
                    node_queue.push({child_ptr, new_child_ptr});
                }
            }
            isfinished_map[current_node_ptr->val] = true;
        }
        return &copied_root;
    }
};
// @lc code=end

int main(){
    Solution object;
    Node node = Node(0);
    Node* node_ptr = &node;
    for(int i = 1; i < 4; i++){
        Node* new_node_ptr = new Node(i);
        node_ptr->neighbors.push_back(new_node_ptr);
        new_node_ptr->neighbors.push_back(node_ptr);
        node_ptr = new_node_ptr;
    }
    node_ptr->neighbors.push_back(&node);
    node.neighbors.push_back(node_ptr);
    auto code = object.cloneGraph(&node);
}