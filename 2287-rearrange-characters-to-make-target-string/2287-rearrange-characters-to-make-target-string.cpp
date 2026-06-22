class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        unordered_map<char,int>tar;
        for(int i=0;i<target.size();i++){
            tar[target[i]]++;
        }
        int ans=INT_MAX;
        for(int i=0;i<target.length();i++){
            char ch=target[i];
            int avilable=mp[ch];
            int required=tar[ch];
            ans=min(ans,avilable/required);
        }
        return ans;
    }
};