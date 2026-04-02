class Solution {
public:
    int findDuplicate(vector<int>& arr) {

        //BOTH O(N)------------------------------------------------------------------
        // unordered_set<int>s;
        // for(int i=0;i<nums.size();i++){
        //     if(s.find(nums[i]) != s.end()){
        //         return nums[i];
        //     }
        //     s.insert(nums[i]);
        // }
        // return -1;

        //SLOW FAST APPROACH-------------------------------------------------------------

        int slow=arr[0];
        int fast=arr[0];
        do{
            slow=arr[slow];
            fast=arr[arr[fast]];
        }
        while(slow!=fast);
        slow=arr[0];
        while(slow!=fast){
            slow=arr[slow];
            fast=arr[fast];
        }return slow;
        
    }
};