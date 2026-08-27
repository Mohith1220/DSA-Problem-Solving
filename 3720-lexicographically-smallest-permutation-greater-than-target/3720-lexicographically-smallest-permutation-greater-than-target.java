class Solution {
    public String lexGreaterPermutation(String s, String target) {
        int n = s.length();
        int[] counts = new int[26];
        for (int i = 0; i < n; i++) {
            counts[s.charAt(i) - 'a']++;
        }
        
        int matchLen = 0;
        while (matchLen < n) {
            int targetCharIdx = target.charAt(matchLen) - 'a';
            if (counts[targetCharIdx] > 0) {
                counts[targetCharIdx]--;
                matchLen++;
            } else {
                break;
            }
        }
        
        for (int i = Math.min(matchLen, n - 1); i >= 0; i--) {
            if (i < matchLen) {
                counts[target.charAt(i) - 'a']++;
            }
            
            int targetCharIdx = target.charAt(i) - 'a';
            for (int c = targetCharIdx + 1; c < 26; c++) {
                if (counts[c] > 0) {
                    StringBuilder sb = new StringBuilder();
                    sb.append(target, 0, i);
                    sb.append((char) ('a' + c));
                    counts[c]--;
                    
                    for (int j = 0; j < 26; j++) {
                        while (counts[j] > 0) {
                            sb.append((char) ('a' + j));
                            counts[j]--;
                        }
                    }
                    return sb.toString();
                }
            }
        }
        
        return "";
    }
}
