class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // count[x] = number of size-k subarrays containing x
        vector<int> count(51, 0);

        for (int i = 0; i <= n - k; i++) {
            // To avoid counting the same number twice
            // inside the same window.
            bool present[51] = {};

            for (int j = i; j < i + k; j++) {
                present[nums[j]] = true;
            }

            // Count this window once for every number present in it
            for (int x = 0; x <= 50; x++) {
                if (present[x]) {
                    count[x]++;
                }
            }
        }

        int ans = -1;

        for (int x = 0; x <= 50; x++) {
            if (count[x] == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};