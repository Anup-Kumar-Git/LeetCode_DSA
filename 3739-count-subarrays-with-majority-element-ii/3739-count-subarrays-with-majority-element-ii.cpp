#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

// Ordered Set
typedef tree<pair<int,int>, null_type, less<pair<int,int>>,
             rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> pref(n, 0);

        // Convert to +1 and -1 and build prefix sum
        for (int i = 0; i < n; i++) {
            if (nums[i] == target)
                pref[i] = 1;
            else
                pref[i] = -1;

            if (i)
                pref[i] += pref[i - 1];
        }

        ordered_set st;

        ll ans = 0;

        // Initial prefix sum = 0
        st.insert({0, -1});

        for (int i = 0; i < n; i++) {

            // Count previous prefix sums smaller than current
            ans += st.order_of_key({pref[i], -1});

            // Insert current prefix
            st.insert({pref[i], i});
        }

        return ans;
    }
};