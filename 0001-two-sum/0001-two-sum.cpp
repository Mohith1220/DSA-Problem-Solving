class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<std::pair<int, int>> vec;
        for (int i = 0; i < nums.size(); ++i) {
            vec.push_back({nums[i], i});
        }
        
        std::sort(vec.begin(), vec.end());
        
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int sum = vec[left].first + vec[right].first;
            if (sum == target) {
                return {vec[left].second, vec[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};
