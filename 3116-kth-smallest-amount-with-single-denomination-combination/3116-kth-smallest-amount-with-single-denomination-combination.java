import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

class Solution {
    private long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    private long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }

    public long findKthSmallest(int[] coins, int k) {
        Arrays.sort(coins);
        List<Integer> cleanCoins = new ArrayList<>();
        for (int c : coins) {
            boolean redundant = false;
            for (int active : cleanCoins) {
                if (c % active == 0) {
                    redundant = true;
                    break;
                }
            }
            if (!redundant) cleanCoins.add(c);
        }

        int n = cleanCoins.size();
        int numSubsets = 1 << n;

        List<long[]> validSubsets = new ArrayList<>();
        long maxPossibleHigh = (long) cleanCoins.get(0) * k;

        for (int mask = 1; mask < numSubsets; ++mask) {
            long currentLcm = 1;
            int bitCount = 0;
            boolean overflow = false;

            for (int i = 0; i < n; ++i) {
                if (((mask >> i) & 1) == 1) {
                    bitCount++;
                    long coin = cleanCoins.get(i);
                    if (coin / gcd(currentLcm, coin) > maxPossibleHigh / currentLcm + 1) {
                        overflow = true;
                        break;
                    }
                    currentLcm = lcm(currentLcm, coin);
                }
            }

            if (!overflow && currentLcm <= maxPossibleHigh) {
                int sign = (bitCount % 2 == 1) ? 1 : -1;
                validSubsets.add(new long[]{currentLcm, sign});
            }
        }

        long low = 1;
        long high = maxPossibleHigh;
        long result = high;

        while (low <= high) {
            long mid = low + (high - low) / 2;
            long count = 0;

            for (long[] subset : validSubsets) {
                count += (mid / subset[0]) * subset[1];
            }

            if (count >= k) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
}
