class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start =1; //initialize 1 becuse 1st element and last element never be peak of mountain
        int end =arr.size()-2;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
                return mid;
            }
            else if(arr[mid-1] < arr[mid]){ //right side search(incremental mountain)
                start= mid+1;
            }
            else{   //left side search(decremental mountain)
                end=mid-1;
            }
            
        }
        return -1;
        
        
    }
    
   
};