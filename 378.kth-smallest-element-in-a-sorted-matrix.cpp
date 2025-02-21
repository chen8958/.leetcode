/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

#include <vector>
#include <deque>
#include <queue>
#include <stdio.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto iterator_compare = [matrix](pair<int,int> p1, pair<int,int> p2){
            return matrix[p1.first][p1.second] > matrix[p2.first][p2.second];
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(iterator_compare)> pq(iterator_compare);
        pair<int,int> current_pair;
        for(int index = 0; index < matrix.size(); index++){
            pq.push(pair<int,int>{index, 0});
        }

        while (k--)
        {
            current_pair = pq.top();
            pq.pop();
            if (current_pair.second + 1 < matrix[current_pair.first].size()){
                pq.push(pair<int,int>{current_pair.first, current_pair.second + 1});
            }
        }        
        return matrix[current_pair.first][current_pair.second];
    }
};
// @lc code=end

int main(){
    Solution object;
    vector<vector<int>> maxtrix = 
    {
        {10,12,16},
        {5,11,13},
        {12,13,15}
    };

    int code = object.kthSmallest(maxtrix , 8);

}
