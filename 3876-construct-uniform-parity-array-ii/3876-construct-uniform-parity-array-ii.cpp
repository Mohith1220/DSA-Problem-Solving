#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_val = nums1[0];
        int odd_count = 0;
        
        for (int x : nums1) {
            if (x < min_val) {
                min_val = x;
            }
            if (x % 2 != 0) {
                odd_count++;
            }
        }
        
        return (odd_count == 0) || (min_val % 2 != 0);
    }
};
