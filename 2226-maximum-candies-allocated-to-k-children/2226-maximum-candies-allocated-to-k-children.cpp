class Solution {
public:
    bool isPossible(vector<int>& candies, long long k, long long mid) {
        long long count = 0;

        for(int i = 0; i < candies.size(); i++) {
            count += candies[i] / mid;
        }

        return count >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long total = 0;

        for(int i = 0; i < candies.size(); i++) {
            total += candies[i];   // ✅ long long
        }

        if(total < k) return 0;

        long long st = 1;
        long long end = total / k;   // ✅ important optimization
        long long ans = 0;

        while(st <= end) {
            long long mid = st + (end - st) / 2;

            if(isPossible(candies, k, mid)) {
                ans = mid;
                st = mid + 1;   // maximize
            } else {
                end = mid - 1;
            }
        }

        return (int)ans;
    }
};
