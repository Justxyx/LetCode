#include <iostream>
using namespace std;
#include <vector>

/*
 * 局部最优 全局最优
 */
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int count = 0;


        int i = 1;
        bool more = true;
        while (i < nums.size()){
            if (i == 1){
                while (nums[i] == nums[i-1]){
                    ++i;
                }
                if (nums[i] > nums[0])
                    more = true;
//                else if(nums[i] == nums[0]){
//                    more = false;
//                    ++i;
//                    continue;
//                }
                else
                    more = false;
                ++ count;
                ++i;
                continue;
            }

            if ((nums[i] > nums[i-1]) && more){
                more = true;
            } else if ((nums[i] > nums[i-1]) && !more){
                more = true;
                ++ count;
            } else if ((nums[i] < nums[i-1]) && more){
                more = false;
                ++ count;
            } else if (nums[i] == nums[i-1]){
                ++i;
                continue;
            }
            else{
                more = false;
            }
            ++ i;
        }
        return count;
    }
};


int main() {
    vector<int> g = {1,7,4,9,2,5};
    Solution solution;
    solution.wiggleMaxLength(g);
}
