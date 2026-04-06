class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_map<int, int> mp;

        // count frequency of each type
        for (int i = 0; i < n; i++) {
            mp[candyType[i]]++;
        }

        int uniqueTypes = mp.size();

        return min(uniqueTypes, n / 2);
        
// USING SET---------------------------------------------------------------
    //     int n = candyType.size();
    //     unordered_set<int> s;
    //     for (int i = 0; i < n; i++) {  // count unique types
    //         s.insert(candyType[i]);
    //     }

    //     return min((int)s.size(), n / 2);
    }
};