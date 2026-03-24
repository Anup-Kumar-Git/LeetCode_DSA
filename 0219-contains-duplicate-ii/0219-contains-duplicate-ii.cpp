// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         int i=0;
//         int j=nums.size()-1;
//         bool ans;
//         int n=0;
//         while(i<j){
//             if(nums[i]!=nums[j]){
//                 ans=false;
//             }else if(nums[i]==nums[j]){
//                 if(abs(i-j)<=k){
//                     ans= true;
//                     n++;
//                     break;
//                 }
//                 ans=false;
            
//             }
//             i++;
            
//         }
        
//         if(n>1) return false;
//         return ans;
        
//     }
// };


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;

        for(int i = 0; i < nums.size(); i++) {
            
            // Step 1: Remove element out of window
            if(i > k) {
                seen.erase(nums[i - k - 1]);
            }

            // Step 2: Check duplicate
            if(seen.count(nums[i])) {
                return true;
            }

            // Step 3: Add current element
            seen.insert(nums[i]);
        }

        return false;
    }
};