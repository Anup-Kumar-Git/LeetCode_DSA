class Solution {
public:
    int maxArea(vector<int>& height) {
        
        //BRUTE FORCE APPROACH(TLE)-------------------------------------------- 
        // int maxWater = 0;
        // for(int i =0;i<height.size();i++){
        //     for(int j=i+1;j<height.size();j++){
        //         int w=j-i;
        //         int ht=min(height[j],height[i]);
        //         int currWater=w*ht;
        //         maxWater=max(currWater,maxWater);
        //     }
        // }return maxWater;
        
        // OPTIMAL APPROACH-----------------------------------------------------

        int lp=0;
        int rp=height.size()-1;
        int maxWater=0;
        while(lp<rp){
            int w=rp-lp; //width
            int ht=min(height[lp],height[rp]); //height of containeer
            int currWater=w*ht;
            maxWater=max(currWater,maxWater);
            height[lp]<height[rp] ? lp++ : rp--;
        }
        return maxWater;
    }
};