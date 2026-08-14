class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0;
        int max_len = 0;
        vector<int> char_counts(26, 0);

        for (int right = 0; right < s.length(); ++right) {
            char_counts[s[right] - 'a']++;

            while (char_counts[s[right] - 'a'] > 2) {
                char_counts[s[left] - 'a']--;
                left++;
            }

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};
