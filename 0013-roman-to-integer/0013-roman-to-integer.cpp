class Solution {
public:
    int romanToInt(string s) {
        map<char,int>mp={{'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}};
        int prev=0;
        int ans=0;
        for(int i=s.length()-1; i>=0; i--){
            int curr=mp[s[i]];
            if(curr<prev){
                ans-=curr;
            }else{
                ans+=curr;
            }
            prev=curr;
        }
        return ans;
        
    }
};