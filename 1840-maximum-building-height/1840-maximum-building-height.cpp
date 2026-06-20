class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restriction) {
        restriction.push_back({1,0});
        restriction.push_back({n,n-1});
        sort(restriction.begin(),restriction.end());
        int m=restriction.size();

        for(int i=1;i<m;i++){
            restriction[i][1]=min(
                restriction[i][1],
                restriction[i-1][1]+
                restriction[i][0]-
                restriction[i-1][0]
            );
        }
        for(int i=m-2;i>=0;i--){
            restriction[i][1]=min(
                restriction[i][1],
                restriction[i+1][1]+
                restriction[i+1][0]-
                restriction[i][0]
            );
        }

        int ans=0;
        for(int i=1;i<m;i++){
            long long id1= restriction[i-1][0];
            long long h1=restriction[i-1][1];
            
            long long id2=restriction[i][0];
            long long h2=restriction[i][1];

            long long d= id2-id1; //gap
            ans= max(ans,(int)(h1+h2+d)/2);

        }
        return ans;
        
    }
};