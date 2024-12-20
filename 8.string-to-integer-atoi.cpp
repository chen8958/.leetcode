/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
#include <string>
#include <stdio.h>
using namespace std;




class Solution {
    enum SIGN{
        POSITIVE,
        NEGATIVE,
        UNDERMINED
    };
public:
    int myAtoi(string s) {
        // check positive or negative
        enum SIGN sign = UNDERMINED;
        int sum = 0;
        // iteration each word
        
        for(auto it = s.begin(); it != s.end();it++){
            // check number hex
            
            if('0' <= *it && *it <= '9'){
                if(sign == POSITIVE || sign == UNDERMINED){
                    if(sum > INT32_MAX/10){
                        sum = INT32_MAX;
                    }else{
                        sum = sum *10 + (*it - '0');
                    }
                    if(sign == UNDERMINED){
                    sign = POSITIVE;
                }
                }else if(sign == NEGATIVE){
                    if(sum < INT32_MIN/10){
                        sum = INT32_MIN;
                    }else{
                        sum = sum *10 - (*it - '0');
                    }
                }
                
            }
            else if(*it == '+' && sign == UNDERMINED){
                sign = POSITIVE;
            }
            else if(*it == '-' && sign == UNDERMINED){
                sign = NEGATIVE;
            }
            else if(*it == ' '){
                continue;
            }
            else{
                break;
            }
        }
        return sum;
    }
};
// @lc code=end
int main(){
    Solution object;
    int value = object.myAtoi("   -042");
    printf(" %d ",value);
}