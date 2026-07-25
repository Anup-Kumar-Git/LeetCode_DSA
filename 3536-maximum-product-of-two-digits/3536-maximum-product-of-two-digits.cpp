class Solution {
public:
    int maxProduct(int n) {
        int first = 0, second = 0;

        while (n > 0) {
            int d = n % 10;

            if (d >= first) {
                second = first;
                first = d;
            } else if (d > second) {
                second = d;
            }

            n /= 10;
        }

        return first * second;
    }
};

// USING VECTOR----------------------------------------
// class Solution {
// public:
//     int maxProduct(int n) {
//         vector<int> digits;

//         while (n > 0) {
//             digits.push_back(n % 10);
//             n /= 10;
//         }

//         sort(digits.begin(), digits.end());

//         int m = digits.size();
//         return digits[m - 1] * digits[m - 2];
//     }
// };