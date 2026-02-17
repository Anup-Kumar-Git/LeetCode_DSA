class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int start = 0;
        int end = n-1;
        while(start<=end){
            int mid= start +(end-start)/2;
            if(mid == 0 && nums[0] != nums[1]) return nums[mid];  //if mid = 1st element
            
            if(mid == (n-1) && nums[n-1] != nums[n-2]) return nums[mid];  //if mid = last element

            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]){   //if mid is single element in array
                return nums[mid];
            }if(mid%2==0){            //even number of index
                if(nums[mid-1]==nums[mid]){ //left array
                    end=mid-1;
                }else {                     //right array
                    start=mid+1;
                }
            }else{                    //odd number od index
                if(nums[mid-1]==nums[mid]){
                   start=mid+1;          //right array
                }else{
                    end=mid-1;           //left array
                }
            }
        }
        return -1;
        
        
    }
};