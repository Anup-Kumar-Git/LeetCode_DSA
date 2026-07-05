class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();
        const int MOD = 1e9 + 7;

        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        score[0][0] = 0;
        ways[0][0] = 1;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                if (board[i][j] == 'X')
                    continue;

                int best = -1;
                long long cnt = 0;

                // from top
                if (i > 0 && score[i - 1][j] != -1)
                    best = max(best, score[i - 1][j]);

                // from left
                if (j > 0 && score[i][j - 1] != -1)
                    best = max(best, score[i][j - 1]);

                // from diagonal
                if (i > 0 && j > 0 && score[i - 1][j - 1] != -1)
                    best = max(best, score[i - 1][j - 1]);

                if (best == -1)
                    continue;

                if (i > 0 && score[i - 1][j] == best)
                    cnt = (cnt + ways[i - 1][j]) % MOD;

                if (j > 0 && score[i][j - 1] == best)
                    cnt = (cnt + ways[i][j - 1]) % MOD;

                if (i > 0 && j > 0 && score[i - 1][j - 1] == best)
                    cnt = (cnt + ways[i - 1][j - 1]) % MOD;

                int value = 0;

                if (board[i][j] >= '1' && board[i][j] <= '9')
                    value = board[i][j] - '0';

                score[i][j] = best + value;
                ways[i][j] = cnt;
            }
        }

        if (ways[n - 1][n - 1] == 0)
            return {0, 0};

        return {score[n - 1][n - 1], ways[n - 1][n - 1]};
    }
};