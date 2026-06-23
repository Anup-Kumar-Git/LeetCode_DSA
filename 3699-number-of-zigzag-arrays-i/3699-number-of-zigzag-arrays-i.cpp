class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;

        int m = r - l + 1;

        vector<long long> up(m + 2), down(m + 2);
        vector<long long> newUp(m + 2), newDown(m + 2);
        vector<long long> pref(m + 2), suff(m + 3);

        for (int v = 1; v <= m; v++) {
            up[v] = v - 1;
            down[v] = m - v;
        }

        for (int len = 3; len <= n; len++) {

            pref[0] = 0;
            for (int i = 1; i <= m; i++) {
                pref[i] = (pref[i - 1] + down[i]) % MOD;
            }

            suff[m + 1] = 0;
            for (int i = m; i >= 1; i--) {
                suff[i] = (suff[i + 1] + up[i]) % MOD;
            }

            for (int v = 1; v <= m; v++) {
                newUp[v] = pref[v - 1];
                newDown[v] = suff[v + 1];
            }

            swap(up, newUp);
            swap(down, newDown);
        }

        long long ans = 0;
        for (int v = 1; v <= m; v++) {
            ans = (ans + up[v] + down[v]) % MOD;
        }

        return ans;
    }
};