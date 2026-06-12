class Solution {
public:

    bool isAlphaNum(char ch){
        if((ch >='0' && ch <='9') || (tolower(ch)>='a' && tolower(ch)<='z')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int st=0;
        int end=s.length()-1;
        while(st<end){
            if(!isAlphaNum(s[st])){
                st++;
                continue;
            }
            if(!isAlphaNum(s[end])){
                end--;
                continue;
            }
            if(tolower(s[st])!=tolower(s[end])){
                return false;
            }
            st++;
            end--;
        }
        return true;
        
    }


    // bool isPalindrome(string s) {
    //     int st=0;
    //     int end=s.length()-1;
    //     while(st<end){
    //         if(!isalnum(s[st])){
    //             st++;
    //             continue;
    //         }
    //         if(!isalnum(s[end])){
    //             end--;
    //             continue;
    //         }
    //         if(tolower(s[st])!=tolower(s[end])){
    //             return false;
    //         }
    //         st++;
    //         end--;
    //     }
    //     return true;
        
    // }
};


//Using recursion------------------------------------------------------
// class Solution {
// public:
//     bool check(string &s,int i) {
//         if(i>=s.size()/2) return true;
//         if(s[i]!=s[s.size()-1-i]) return false;
//         return check(s,i+1);
        
//     }
//     bool isPalindrome(string s){
//         string cleaned="";
//         for(int i=0;i<s.size();i++){
//             char ch=s[i];
//             if(isalnum(ch)){
//                 cleaned +=tolower(ch);
//             }
//         }
//         return check(cleaned,0);
//     }
// };