/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
#include <string>
#include <vector>
#include <list>




class Solution {
public:
    std::string intToRoman(int num) {
        std::list<char> reverse_roman_word;
        std::string roman_word;
        int single_num;
        std::vector<std::vector<char>> roman_tables(4);
        auto table_iterator = roman_tables.begin();
        roman_tables[0].push_back('I');
        roman_tables[0].push_back('V');
        roman_tables[0].push_back('X');

        roman_tables[1].push_back('X');
        roman_tables[1].push_back('L');
        roman_tables[1].push_back('C');

        roman_tables[2].push_back('C');
        roman_tables[2].push_back('D');
        roman_tables[2].push_back('M');

        roman_tables[3].push_back('M');


        while(num){
            single_num = num%10;
            switch(single_num){
                case 0:
                    break;
                case 1:
                case 2:
                case 3:
                    //push
                    for(int i = 0; i < single_num; i++){
                        reverse_roman_word.push_front((*table_iterator)[0]);
                    }
                    break;
                case 4:
                    //push
                    reverse_roman_word.push_front((*table_iterator)[1]);
                    reverse_roman_word.push_front((*table_iterator)[0]);
                    break;
                case 5:
                case 6:
                case 7:
                case 8:
                    for(int i = 0; i < (single_num - 5); i++){
                        reverse_roman_word.push_front((*table_iterator)[0]);
                    }
                    reverse_roman_word.push_front((*table_iterator)[1]);
                    break;
                case 9:
                    reverse_roman_word.push_front((*table_iterator)[2]);
                    reverse_roman_word.push_front((*table_iterator)[0]);
                    break;
                    //push
            }
            num = num/10;
            table_iterator++;
        }

        for(auto it = reverse_roman_word.begin(); it != reverse_roman_word.end(); it++) {
            roman_word.push_back(*it);
        }
        return roman_word;
    }
};
// @lc code=end
int main(){
    Solution object;
    object.intToRoman(3749);
}
