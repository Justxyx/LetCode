#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <numeric>
#include <set>
#include <unordered_set>
#include <cmath>

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        int sum = 1;
        int maxs = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1])
                ++ sum;
            else {
                sum = 1;
                maxs = max(sum,maxs);
            }
        }
        return maxs;
    }
};

int main() {
    return 0;
}

