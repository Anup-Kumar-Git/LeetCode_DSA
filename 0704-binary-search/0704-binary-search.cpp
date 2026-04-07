class Solution {
public:
    // int search(vector<int>& nums, int target) {
    //     int n= nums.size();
    //     int st=0;
    //     int end=n-1;
    //     while(st<=end){
    //         int mid=st + (end-st)/2;
    //         if(nums[mid]==target){
    //             return mid;
    //         }else if(nums[mid]>=target){
    //             end=mid-1;
    //         }else{
    //             st=mid+1;
    //         }

    //     }
    //     return -1;
        

    // }


//USING RECURSION----------------------------------------------------------------------------
    int binSearch(vector<int>nums,int target,int st,int end){
        if(st <= end){
            int mid= st+ (end-st)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid] > target){
                return binSearch(nums,target,st,mid-1);
            }else{
                return binSearch(nums,target,mid+1,end);
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return binSearch(nums,target,0,nums.size()-1);

    }
};