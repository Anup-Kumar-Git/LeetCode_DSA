class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int srow=0;
        int scol=0;
        int erow=m-1;
        int ecol=n-1;
        vector<int>ans;

        while(srow <= erow && scol <= ecol){

            //top
            for(int j=scol;j<=ecol;j++){
                ans.push_back(matrix[srow][j]);
            }

            //right
            for(int j=srow+1;j<=erow;j++){
                ans.push_back(matrix[j][ecol]);
            }

            //bottom
            if(srow < erow){
                for(int j=ecol-1;j>=scol;j--){
                    ans.push_back(matrix[erow][j]);
                }
            }
            

            //left
            if(scol < ecol){
                for(int j=erow-1;j>=srow+1;j--){
                    ans.push_back(matrix[j][scol]);
                }
            }
            
            srow++;
            erow--;
            scol++;
            ecol--;
        }
        return ans;
        
    }
};