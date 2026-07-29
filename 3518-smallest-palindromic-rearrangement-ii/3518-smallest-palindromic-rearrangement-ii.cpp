class Solution {
public:
    const long long LIM = 1000000;

    long long nCr(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);

        long long ans = 1;

        for (int i = 1; i <= r; i++) {
            long long num = n - r + i;
            long long den = i;

            long long g = gcd(num, den);
            num /= g;
            den /= g;

            g = gcd(ans, den);
            ans /= g;
            den /= g;

            if (ans > LIM / num)
                return LIM + 1;

            ans *= num;
            ans /= den;

            if (ans > LIM)
                return LIM + 1;
        }

        return ans;
    }

    long long countWays(vector<int>& cnt) {
        int rem = 0;
        for (int x : cnt)
            rem += x;

        long long ways = 1;

        for (int x : cnt) {
            if (x == 0) continue;

            long long choose = nCr(rem, x);

            if (ways > LIM / choose)
                return LIM + 1;

            ways *= choose;

            if (ways > LIM)
                return LIM + 1;

            rem -= x;
        }

        return ways;
    }

    string smallestPalindrome(string s, int k) {

        vector<int> freq(26);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26);

        char mid = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] & 1)
                mid = 'a' + i;
        }

        if (countWays(half) < k)
            return "";

        string first;

        int len = s.size() / 2;

        for (int pos = 0; pos < len; pos++) {

            for (int c = 0; c < 26; c++) {

                if (!half[c])
                    continue;

                half[c]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    first.push_back('a' + c);
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string second = first;
        reverse(second.begin(), second.end());

        if (mid)
            return first + string(1, mid) + second;

        return first + second;
    }
};