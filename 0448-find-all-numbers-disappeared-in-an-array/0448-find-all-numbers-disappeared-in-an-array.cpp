class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // int n=nums.size();
        // sort(nums.begin(),nums.end());
        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     if(nums[i]!=i+1){
        //         ans.push_back(i+1);
        //     }
        // }
        // return ans;

        int n=nums.size();
        vector<int>ans;
        vector<int>freq(n+1,0);
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(freq[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};