class Solution {
    public int distinctSubseqII(String s) {
        final long MOD = 1_000_000_007L;

        long dp = 1;
        long[] last = new long[26];

        for (char ch : s.toCharArray()) {
            int c = ch - 'a';

            long newDp = (2 * dp) % MOD;
            newDp = (newDp - last[c] + MOD) % MOD;

            last[c] = dp;
            dp = newDp;
        }

        return (int) ((dp - 1 + MOD) % MOD);
    }
}