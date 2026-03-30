class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix[0].size();
        int stRow=0;
        int endRow=matrix.size()-1;
        //find the actual row.
        while(stRow<=endRow){
            int midRow=stRow + (endRow-stRow)/2;
            if(target >= matrix[midRow][0] && target <= matrix[midRow][n-1]){
                //search in specific column.
                int st=0;
                int end=n-1;
                while(st<=end){
                    int mid=st+(end-st)/2;
                    if(target ==matrix[midRow][mid]){
                        return true;
                    }else if(target > matrix[midRow][mid]){
                        st=mid+1;
                    }else{
                        end=mid-1;
                    }
                    
                }
                return false;

            }else if(target >= matrix[midRow][n-1]){
                stRow=midRow+1;
            }else{
                endRow=midRow-1;
            }
        }
        return false;
    }
};