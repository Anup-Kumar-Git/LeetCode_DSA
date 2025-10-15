class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int currCount =1;
        int prevCount =0;
        int maxi =1;
        for(int i = 1; i<n; i++){
            if(nums[i] > nums[i-1]){
                currCount++;

            }else{
                prevCount = currCount;
                currCount =1;
            }
            maxi =max(maxi,min(currCount,prevCount));
            maxi = max(maxi,currCount /2);
        }
        return maxi;
        
    }
};