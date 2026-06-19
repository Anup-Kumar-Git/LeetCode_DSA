class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int result=0;
        int altitude=0;
        for(int i=0;i<gain.size();i++){
            altitude +=gain[i];
            result=max(altitude,result);
            
            
        }
        return result;
        
    }
};