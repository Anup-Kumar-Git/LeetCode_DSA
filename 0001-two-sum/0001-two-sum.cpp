class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp; // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (mp.find(diff) != mp.end()) {
                return {mp[diff], i}; // Found the pair
            }
            mp[nums[i]] = i;
        }

        return {}; // Just for formality; guaranteed one valid answer exists
    }
};