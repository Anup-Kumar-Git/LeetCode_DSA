class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> res;

        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == "C") {
                res.pop_back();
            } 
            else if (ops[i] == "D") {
                res.push_back(2 * res.back());
            } 
            else if (ops[i] == "+") {
                res.push_back(res.back() + res[res.size() - 2]);
            } 
            else {
                res.push_back(stoi(ops[i]));
            }
        }

        int sum = 0;
        for (int i = 0; i < res.size(); i++) {
            sum += res[i];
        }

        return sum;
        
    }
};