class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp;
        for(int i=0;i<text.length();i++){
            mp[text[i]]++;
        }
        string word="balloon";
        int ans=INT_MAX;
        for(int i=0;i<word.length();i++){
            int required=1;
            if (word[i] == 'l' || word[i]=='o'){
                required = 2;
            }
            ans=min(ans,mp[word[i]]/required);
            if (word[i] == 'l'  || word[i]=='o'){
                i++;
            }
        }
    //USING MAP TO STORE THE WORD ALSO-----------------------------------
        // string word="balloon";
        // unordered_map<char,int>wrd;
        // for(int i=0;i<word.length();i++){
        //     wrd[word[i]]++;
        // }

        // int ans=INT_MAX;
        // for(int i=0;i<word.length();i++){
        //     char ch=word[i];
        //     int avilable=mp[ch];
        //     int required=wrd[ch];
        //     ans=min(ans,avilable/required);
        // }
        
        return ans;
        
    }
};