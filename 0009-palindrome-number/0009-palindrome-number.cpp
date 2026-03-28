class Solution {
public:
    bool isPalindrome(int n) {
        int rev=0;
        int dup=n;
        while(n>0){
            int dig=n%10;
            if(rev > INT_MAX/10 || rev < INT_MIN/10){
                return false;
            }
            rev=rev*10+dig;
            n=n/10;
        }
        if(rev != dup){
            return false;
        }else{
            return true;
        }
        
    }
};