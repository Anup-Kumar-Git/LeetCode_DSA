class Solution {
public:
    char processStr(string s, long long k) {

        int n = s.size();
        vector<long long> len(n);

        long long cur = 0;

        // Step 1: store lengths
        for(int i = 0; i < n; i++) {

            if(islower(s[i]))
                cur++;

            else if(s[i] == '*') {
                if(cur > 0)
                    cur--;
            }

            else if(s[i] == '#')
                cur = min((long long)1e15, cur * 2);

            len[i] = cur;
        }
        if(k >= cur)
            return '.';

        // Step 2: go backwards
        for(int i = n - 1; i >= 0; i--) {

            long long prevLen = (i == 0 ? 0 : len[i - 1]);

            if(islower(s[i])) {

                if(k == prevLen)
                    return s[i];
            }

            else if(s[i] == '#') {

                if(prevLen > 0)
                    k %= prevLen;
            }

            else if(s[i] == '%') {

                if(prevLen > 0)
                    k = prevLen - 1 - k;
            }
        }
        return '.';
    }
};