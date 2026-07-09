class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {

        vector<int> comp(n);
        int component = 0;

        comp[0] = component;

        // Assign component number to every node
        for (int i = 1; i < n; i++) {

            if (nums[i] - nums[i - 1] > maxDiff) {
                component++;        // Start a new component
            }

            comp[i] = component;
        }

        vector<bool> ans;

        // Answer each query
        for (auto &q : queries) {

            if (comp[q[0]] == comp[q[1]])
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};