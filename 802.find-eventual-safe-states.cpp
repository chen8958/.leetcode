/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    // bool DFS_find_backward_edge(const vector<vector<int>>& graph, int node, vector<bool> &visited_map, vector<bool> &finished_map){
    //     visited_map[node] = true;
    //     bool detected_backward_edge = false;
    //     for(int child_node : graph[node]){
    //         if(finished_map[child_node] == true) continue;
    //         if(visited_map[child_node] == true){
    //             detected_backward_edge = true;
    //             continue;
    //         }
    //         detected_backward_edge = detected_backward_edge |
    //                                 DFS_find_backward_edge(
    //                                     graph,
    //                                     child_node,
    //                                     visited_map,
    //                                     finished_map
    //                                 ); 
    //     }
    //     finished_map[node] = true;
    //     return detected_backward_edge;
    // }
    // DFS find backward path and except all relative node
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> visited_map(graph.size(), false);
        vector<bool> finished_map(graph.size(), false);
        vector<bool> is_safe_node(graph.size(), true);
        vector<int> safe_node;
        function<bool(int)> DFS_find_backward_edge_function;
        DFS_find_backward_edge_function = [&graph, &visited_map, &finished_map, &DFS_find_backward_edge_function, &is_safe_node](int current_node){
            visited_map[current_node] = true;
            bool detected_backward_edge = false;
            for(int child_node : graph[current_node]){
                if(finished_map[child_node] == true){
                    if(is_safe_node[child_node] == false) detected_backward_edge = true;
                    continue;
                    }
                if(visited_map[child_node] == true){
                    detected_backward_edge = true;
                    continue;
                }
                detected_backward_edge = detected_backward_edge |
                                        DFS_find_backward_edge_function(
                                            child_node
                                        ); 
            }
            if(detected_backward_edge == true){
                is_safe_node[current_node] = false;
            }
            finished_map[current_node] = true;
            return detected_backward_edge;
        };
        for(int start_node = 0; start_node < graph.size(); start_node++){
            if(finished_map[start_node] == false){
                DFS_find_backward_edge_function(start_node);
            }
        }
        for (int index = 0; index < is_safe_node.size();index++){
            if(is_safe_node[index])safe_node.push_back(index);
        }
        return safe_node;
    }
};
// @lc code=end

