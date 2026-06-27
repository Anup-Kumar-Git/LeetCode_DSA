class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int x : nums) freq[x]++;

        int ans = 1;

        // Handle 1 separately
        if (freq.count(1)) {
            int c = freq[1];
            ans = max(ans, (c & 1) ? c : c - 1);
        }

        for (auto &[x, cnt] : freq) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (freq.count(cur) && freq[cur] >= 2) {
                len++;

                // Stop if next square cannot exist
                if (cur > 31622) break;

                cur = cur * cur;
            }

            if (freq.count(cur) && freq[cur] >= 1 && freq[cur] < 2)
                ans = max(ans, 2 * len + 1);
            else
                ans = max(ans, max(1, 2 * len - 1));
        }

        return ans;
    }
};