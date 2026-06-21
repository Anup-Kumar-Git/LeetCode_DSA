class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans=0;
        int result=0;
        sort(costs.begin(),costs.end());
        for(int i=0;i<costs.size();i++){
            result += costs[i];
            if(result > coins){
                ans=i;
                break;
               
            }
        }
        if(result <= coins){
            return costs.size();
        }
        return ans;    
        
        
    }
};