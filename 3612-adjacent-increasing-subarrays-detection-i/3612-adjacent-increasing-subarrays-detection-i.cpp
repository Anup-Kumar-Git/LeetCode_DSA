class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> increasing(n+1,1);
        for (int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                increasing[i+1] += increasing[i];
            }else{
                increasing[i+1]=1;
            }
        }
        for (int i = k; i<=n-k; i++){
            if(increasing[i] >= k && increasing[i+k]>=k){
                return true;
            }
        }
        return false;
        
    }
};