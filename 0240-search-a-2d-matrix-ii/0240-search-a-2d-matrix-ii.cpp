class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        //mid==right top corner ||mid==left bottom corner
        int row=0;
        int col=n-1;
        while(row < m && col>=0){
            if(target==matrix[row][col]){  //mid==right top corner
                return true;
            }else if(target < matrix[row][col]){
                col--;
            }else{
                row++;
            }
        }
        return false;
        
    }
};