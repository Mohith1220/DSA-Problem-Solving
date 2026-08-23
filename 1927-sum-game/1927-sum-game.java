class Solution {
    public boolean sumGame(String num) {
        int n = num.length();
        int sumLeft = 0, sumRight = 0;
        int cntLeft = 0, cntRight = 0;

        for (int i = 0; i < n / 2; i++) {
            char c = num.charAt(i);
            if (c == '?') {
                cntLeft++;
            } else {
                sumLeft += c - '0';
            }
        }

        for (int i = n / 2; i < n; i++) {
            char c = num.charAt(i);
            if (c == '?') {
                cntRight++;
            } else {
                sumRight += c - '0';
            }
        }

        int sumDiff = sumLeft - sumRight;
        int cntDiff = cntLeft - cntRight;

        if (cntDiff % 2 != 0) {
            return true;
        }
        return sumDiff + (cntDiff / 2) * 9 != 0;
    }
}