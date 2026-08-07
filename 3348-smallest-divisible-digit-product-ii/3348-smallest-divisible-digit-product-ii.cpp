class Solution {
public:
    using ll = long long;

    int need[4]; // powers of 2, 3, 5, 7

    vector<array<int, 4>> contrib = {
        {0, 0, 0, 0}, // 0
        {0, 0, 0, 0}, // 1
        {1, 0, 0, 0}, // 2
        {0, 1, 0, 0}, // 3
        {2, 0, 0, 0}, // 4
        {0, 0, 1, 0}, // 5
        {1, 1, 0, 0}, // 6
        {0, 0, 0, 1}, // 7
        {3, 0, 0, 0}, // 8
        {0, 2, 0, 0}  // 9
    };

    // Computes EXACT minimum digits required to cover remaining prime powers
    int minDigitsNeeded(array<int, 4> rem) {
        int p2 = rem[0], p3 = rem[1], p5 = rem[2], p7 = rem[3];
        int count = p5 + p7;

        int cnt8 = p2 / 3; p2 %= 3;
        int cnt9 = p3 / 2; p3 %= 2;

        count += cnt8 + cnt9;

        if (p2 == 2 && p3 == 1) {
            count += 2; // e.g. 4 and 3, or 6 and 2
        } else if (p2 > 0 || p3 > 0) {
            count += 1; // any single leftover combination (6, 4, 3, or 2)
        }

        return count;
    }

    bool possible(int len, array<int, 4> rem) {
        return minDigitsNeeded(rem) <= len;
    }

    string buildSuffix(int len, array<int, 4> rem) {
        string ans;
        for (int i = 0; i < len; i++) {
            for (int d = 1; d <= 9; d++) {
                array<int, 4> nxt = rem;
                for (int k = 0; k < 4; k++)
                    nxt[k] = max(0, nxt[k] - contrib[d][k]);

                if (possible(len - i - 1, nxt)) {
                    ans.push_back(char('0' + d));
                    rem = nxt;
                    break;
                }
            }
        }
        return ans;
    }

    string smallestNumber(string num, long long t) {
        ll x = t;
        need[0] = need[1] = need[2] = need[3] = 0;

        while (x % 2 == 0) { need[0]++; x /= 2; }
        while (x % 3 == 0) { need[1]++; x /= 3; }
        while (x % 5 == 0) { need[2]++; x /= 5; }
        while (x % 7 == 0) { need[3]++; x /= 7; }
        if (x != 1) return "-1";

        int n = num.size();

        int first_zero = n;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
        }

        vector<array<int, 4>> pref(n + 1);
        pref[0] = {0, 0, 0, 0};
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i];
            if (num[i] != '0') {
                for (int k = 0; k < 4; k++)
                    pref[i + 1][k] += contrib[num[i] - '0'][k];
            }
        }

        // Check num itself
        if (first_zero == n) {
            array<int, 4> rem;
            for (int k = 0; k < 4; k++)
                rem[k] = max(0, need[k] - pref[n][k]);
            if (rem == array<int, 4>{0, 0, 0, 0})
                return num;
        }

        // Try replacing num[i] with a digit d > num[i]
        for (int i = min(n - 1, first_zero); i >= 0; i--) {
            array<int, 4> have = pref[i];

            int start_digit = (i < first_zero) ? (num[i] - '0' + 1) : 1;

            for (int d = start_digit; d <= 9; d++) {
                auto cur = have;
                for (int k = 0; k < 4; k++)
                    cur[k] += contrib[d][k];

                array<int, 4> rem;
                for (int k = 0; k < 4; k++)
                    rem[k] = max(0, need[k] - cur[k]);

                if (possible(n - i - 1, rem)) {
                    string ans = num.substr(0, i);
                    ans.push_back(char('0' + d));
                    ans += buildSuffix(n - i - 1, rem);
                    return ans;
                }
            }
        }

        // Increase string length if required
        for (int len = n + 1; ; len++) {
            array<int, 4> rem = {need[0], need[1], need[2], need[3]};
            if (possible(len, rem))
                return buildSuffix(len, rem);
        }

        return "-1";
    }
};