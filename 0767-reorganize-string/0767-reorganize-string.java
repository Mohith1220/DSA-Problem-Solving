import java.util.*;

class Solution {
    public String reorganizeString(String s) {
        int[] counts = new int[26];
        int maxCount = 0;
        char maxChar = ' ';
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            counts[ch - 'a']++;
            if (counts[ch - 'a'] > maxCount) {
                maxCount = counts[ch - 'a'];
                maxChar = ch;
            }
        }
        
        if (maxCount > (s.length() + 1) / 2) {
            return "";
        }
        
        char[] result = new char[s.length()];
        int index = 0;
        
        while (counts[maxChar - 'a'] > 0) {
            result[index] = maxChar;
            index += 2;
            counts[maxChar - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            while (counts[i] > 0) {
                if (index >= result.length) {
                    index = 1;
                }
                result[index] = (char) (i + 'a');
                index += 2;
                counts[i]--;
            }
        }
        
        return String.valueOf(result);
    }
}
