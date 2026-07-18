#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int findGCD(std::vector<int>& nums) {
        int min_val = *std::min_element(nums.begin(), nums.end());
        int max_val = *std::max_element(nums.begin(), nums.end());
        return std::gcd(min_val, max_val);
    }
};
