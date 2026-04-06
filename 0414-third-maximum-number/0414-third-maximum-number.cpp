class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int count = 1; //nums[n-1] is largest.
        int n = nums.size();

        for (int i = n - 2; i >= 0; i--) {  //loop start from 2nd last element
            if (nums[i] != nums[i + 1]) {
                count++;
            }
            if (count == 3) return nums[i];
        }

        return nums[n - 1]; // if 3rd max doesn't exist.
    }
};