class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(256, 0); 
        int left = 0;
        int maxLen = 0;
        
        for (int right = 0; right < s.length(); right++) {
            count[s[right]]++;
            
            while (count[s[right]] > 1) {
                count[s[left]]--;
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};
