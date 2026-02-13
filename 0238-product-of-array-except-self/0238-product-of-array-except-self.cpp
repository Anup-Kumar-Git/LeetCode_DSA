class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        //BRUTE FORCE APPROACH(TLE)----------------------------------------------------------------- 
        // vector<int>ans (nums.size(),1); //used to store answer
        // for(int i=0;i<nums.size();i++){
        //     for(int j=0;j<nums.size();j++){
        //         if(i!=j){ //calculate value expect same index
        //             ans[i] *=nums[j];
        //         }
        //     }    
        // }return ans;

    // OPTIMAL but SPACE COMPLEXITY IS 0(N)-------------------------------------------------------------
        // int n=nums.size();
        // vector<int>ans(n,1);
        // vector<int>prefix(n,1);
        // vector<int>sufix(n,1);
        // // prefix
        // for(int i=1;i<n;i++){
        //     prefix[i]=prefix[i-1]*nums[i-1];
        // }
        // // sufix
        // for(int i=n-2;i>=0;i--){
        //     sufix[i]=sufix[i+1]*nums[i+1];
        // }
        // // store answer
        // for(int i=0;i<n;i++){
        //     ans[i]=prefix[i]*sufix[i];
        // }
        // return ans;


    // BEST OPTIMAL APPROACH

        int n=nums.size();
        vector<int>ans(n,1);
        // prefix
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        // sufix
        int sufix=1;
        for(int i=n-2;i>=0;i--){
            sufix *=nums[i+1];
            ans[i] *=sufix;;
        }
        return ans;
    }
};