class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // int n=nums.size()-1;
        // int ans=1;
        // for(int i=0;i<=n-2;i++){
        //     int product=nums[i]*nums[i+1]*nums[i+2];
        //     if(product>0){
        //         ans=max(ans,product);
        //     }else{
        //         ans=min(ans,product);
        //     }
        // }
        // return ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int p1 = nums[n-1] * nums[n-2] * nums[n-3];
        int p2 = nums[0] * nums[1] * nums[n-1];

        return max(p1, p2);
        
    }
};