class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int count=0;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum +=nums[j];
        //         if(sum==k) count++;
        //     }
        // }
        // return count;
        
//OPTIMAL O(N)----------------------------------------------------------------------------------
        int n=nums.size();
        int count=0;
        vector<int>prefixSum(n,0);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        unordered_map<int,int>mp;
        for(int j=0;j<n;j++){
            if(prefixSum[j]==k) count++;
            int val = prefixSum[j] - k;
            if(mp.find(val) != mp.end()){
                count += mp[val];
            }

            if(mp.find(prefixSum[j]) == mp.end()){
                mp[prefixSum[j]]==0;
            }
            mp[prefixSum[j]]++;
        }
        return count;
    }
};