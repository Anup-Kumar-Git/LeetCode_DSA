class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        vector<int> pos;      // positions of non-zero digits
        vector<int> digit;    // non-zero digits

        // Store only non-zero digits
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int n = digit.size();

        // powers of 10
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        // prefix sum of digits
        vector<long long> prefSum(n + 1, 0);

        // prefix concatenated value
        vector<long long> prefValue(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefSum[i + 1] = prefSum[i] + digit[i];
            prefValue[i + 1] = (prefValue[i] * 10 + digit[i]) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            // first non-zero digit >= l
            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();

            // last non-zero digit <= r
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            long long sum = prefSum[R + 1] - prefSum[L];

            int len = R - L + 1;

            long long x = (prefValue[R + 1]
                          - (prefValue[L] * pow10[len]) % MOD
                          + MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};