class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp;
        for(int i=0;i<text.length();i++){
            mp[text[i]]++;
        }
        string word="balloon";
        unordered_map<char,int>wrd;
        for(int i=0;i<word.length();i++){
            wrd[word[i]]++;
        }


        int ans=INT_MAX;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            int avilable=mp[ch];
            int required=wrd[ch];
            ans=min(ans,avilable/required);
        }
        return ans;
        
    }
};