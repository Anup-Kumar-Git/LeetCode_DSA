class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    //     int n=nums.size();
        
    //     set<vector<int>>uniqTri;
    //     for(int i=0;i<n;i++){
    //         int tar= -nums[i];
    //         set<int>s;
    //         for(int j=i+1;j<n;j++){
    //             int third=tar-nums[j];
    //             if(s.find(third) != s.end()){
    //                 vector<int>trip={nums[i], nums[j], third};
    //                 sort(trip.begin(),trip.end());
    //                 uniqTri.insert(trip);
    //             }
    //             s.insert(nums[j]);
    //         }
    //     }
    //     vector<vector<int>>ans(uniqTri.begin(),uniqTri.end());
    //     return ans;
    // }


        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }else if(sum>0){
                    k--;
                }else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                }
            }
        }
        return ans;
    }
};