class Solution {
public:

    void allSubset(vector<int>& nums,vector<int>& ans,int i,vector<vector<int>>&getSubset){
        if(i==nums.size()){
            getSubset.push_back({ans});
            return;
        }
        //include
        ans.push_back(nums[i]);
        allSubset(nums,ans,i+1,getSubset);

        ans.pop_back();  //backtrack
        //exclude
        allSubset(nums,ans,i+1,getSubset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> getSubset;
        vector<int>ans;
        allSubset(nums,ans,0,getSubset);
        return getSubset;

        
    }
};