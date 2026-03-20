class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int pivot=-1;
        int n=arr.size();
        //1st step:-  find the pivot------------------------------
        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                pivot=i;
                break;
            }
        }
        if(pivot==-1){
            reverse(arr.begin(),arr.end());
            return;
        }

        //2nd step:-  next larger element to pivot------------------------
        for(int i=n-1;i>pivot;i--){
            if(arr[i]>arr[pivot]){
                swap(arr[i],arr[pivot]);
                break;
            }
        }
        //3rd step:-  if element arrter pivot in increasing order-------------
        // reverse(arr.begin() + pivot+1,arr.end());
        int i=pivot+1;
        int j=n-1;
        while(i<=j){
            swap(arr[i],arr[j]);
            i++;
            j--;

        }
        
    }
};