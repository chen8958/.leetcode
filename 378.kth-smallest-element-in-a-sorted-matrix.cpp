/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

#include <vector>
#include <deque>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto vector_compare = [](vector<int> v1, vector<int> v2){
            if(v2.size() == 0){
                return false;
            }
            if(v1.size() == 0){
                return true;
            }
            if(v1.front() > v2.front()){
                return true;
            }
            return false;
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(vector_compare)> pq(vector_compare, matrix);

        while(k--){
            if(k==0){
                return pq.top().front();
            }
            vector<int> queue = pq.top();
            pq.pop();
            pq.push( vector<int>{queue.begin()+1,queue.end()} );
        }
/*
    1. heap only accept vector container?
    a. not good, it need dynamic access, the list is only for endian pop and push. deque is better.
    2. when did the queue do compare function?
    b. only do it when pop and push
*/
        return 0;
    }
};
// @lc code=end

int main(){
    Solution object;
    vector<vector<int>> maxtrix = {{10,12,16},{5,11,13},{12,13,15}};

    auto code = object.kthSmallest(maxtrix , 8);
}
