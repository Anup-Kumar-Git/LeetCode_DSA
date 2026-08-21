class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b, long long limit) {
        long long g = gcd(a, b);

        // Prevent overflow and unnecessary calculation
        if (a / g > limit / b)
            return limit + 1;

        return (a / g) * b;
    }

    long long countAmounts(long long x, vector<int>& coins) {
        int n = coins.size();
        long long total = 0;

        // Enumerate all non-empty subsets
        for (int mask = 1; mask < (1 << n); mask++) {
            long long currentLCM = 1;
            int bits = 0;
            bool tooLarge = false;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    currentLCM = lcm(currentLCM, coins[i], x);

                    if (currentLCM > x) {
                        tooLarge = true;
                        break;
                    }
                }
            }

            if (tooLarge)
                continue;

            long long cnt = x / currentLCM;

            if (bits % 2 == 1)
                total += cnt;
            else
                total -= cnt;
        }

        return total;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (countAmounts(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};