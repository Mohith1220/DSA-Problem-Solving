import java.util.ArrayList;
import java.util.List;

class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        List<Integer> onesIndices = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                onesIndices.add(i);
            }
        }
        
        if (onesIndices.size() < k) {
            return "";
        }
        
        String result = "";
        int minLength = Integer.MAX_VALUE;
        
        for (int i = 0; i <= onesIndices.size() - k; i++) {
            int start = onesIndices.get(i);
            int end = onesIndices.get(i + k - 1);
            
            String candidate = s.substring(start, end + 1);
            int currentLength = candidate.length();
            
            if (currentLength < minLength) {
                minLength = currentLength;
                result = candidate;
            } else if (currentLength == minLength) {
                if (candidate.compareTo(result) < 0) {
                    result = candidate;
                }
            }
        }
        
        return result;
    }
}
