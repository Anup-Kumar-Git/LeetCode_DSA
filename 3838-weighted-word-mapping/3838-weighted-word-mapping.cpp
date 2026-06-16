class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(int i=0;i<words.size();i++){
            int sum=0;
            for(int j=0;j<words[i].length();j++){
                sum+= weights[words[i][j]-'a'];
            }
            int mod=sum%26;
            ans.push_back('z'-mod);
        }
        return ans;
        
    }
};