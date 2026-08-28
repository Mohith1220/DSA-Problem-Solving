import java.util.Arrays;

class Solution {
    public String lexPalindromicPermutation(String s, String target) {
        int n = s.length();
        int[] cnt = new int[26];
        for (int i = 0; i < n; i++) {
            cnt[s.charAt(i) - 'a']++;
        }
        int oddCount = 0;
        char mid = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 != 0) {
                oddCount++;
                mid = (char) ('a' + i);
            }
        }
        if (oddCount > 1) {
            return "";
        }
        int[] halfCnt = new int[26];
        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
        }
        
        int halfLen = n / 2;
        char[] resHalf = new char[halfLen];
        boolean deviated = false;
        for (int i = 0; i < halfLen; i++) {
            char tChar = target.charAt(i);
            boolean found = false;
            
            for (int j = 0; j < 26; j++) {
                if (halfCnt[j] <= 0) continue;
                
                char c = (char) ('a' + j);
                if (deviated) {
                    resHalf[i] = c;
                    halfCnt[j]--;
                    found = true;
                    break;
                } else {
                    if (c < tChar) {
                        continue;
                    } else if (c > tChar) {
                        resHalf[i] = c;
                        halfCnt[j]--;
                        deviated = true;
                        found = true;
                        break;
                    } else {
                        halfCnt[j]--;
                        if (canFormGreater(resHalf, i, c, halfCnt, mid, target)) {
                            resHalf[i] = c;
                            found = true;
                            break;
                        }
                        halfCnt[j]++;
                    }
                }
            }
            if (!found) {
                return "";
            }
        }
        StringBuilder sb = new StringBuilder();
        for (char c : resHalf) {
            sb.append(c);
        }
        String firstHalf = sb.toString();
        if (mid != 0) {
            sb.append(mid);
        }
        sb.append(new StringBuilder(firstHalf).reverse());
        
        String fullAns = sb.toString();
        return fullAns.compareTo(target) > 0 ? fullAns : "";
    }
    
    private boolean canFormGreater(char[] resHalf, int currIdx, char currChar, int[] halfCnt, char mid, String target) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < currIdx; i++) {
            sb.append(resHalf[i]);
        }
        sb.append(currChar);
        for (int j = 25; j >= 0; j--) {
            int count = halfCnt[j];
            while (count > 0) {
                sb.append((char) ('a' + j));
                count--;
            }
        }
        
        String firstHalf = sb.toString();
        if (mid != 0) {
            sb.append(mid);
        }
        sb.append(new StringBuilder(firstHalf).reverse());
        
        return sb.toString().compareTo(target) > 0;
    }
}
