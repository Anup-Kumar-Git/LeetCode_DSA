class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int j = 0; // The index of the last unique element found
        
        for (int i = 1; i < nums.size(); i++) {
            // If the current element is different from the last unique element
            if (nums[i] != nums[j]) {
                j++;             // Move the unique pointer forward
                nums[j] = nums[i]; // Update it with the new unique value
            }
        }
        
        // Return the number of unique elements (index + 1)
        return j + 1;
    }
};