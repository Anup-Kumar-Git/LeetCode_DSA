class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        //BRUTE FORCE APPROACH-----------------------------------------------
        // vector<int>ans;
        // for(int i=0;i<nums.size();i++){
        //     int frist=nums[i];
        //     for(int j=i+1;j<nums.size();j++){
        //         int second=nums[j];
        //         int sum=frist+second;
        //         if(target==sum){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //         }
        //     }
        // }
        // return ans;



        //OPTIMAL APPROACH------------------------------------------------------
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int frist=nums[i];
            int sec=target-frist;
            if(mp.find(sec)!=mp.end()){
                ans.push_back(i);
                ans.push_back(mp[sec]);
                break;
            }
            mp[frist]=i;
        }
        return ans;
    }

};