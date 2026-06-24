class Solution {
public:
    static const long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();

        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                long long val = A[i][k];

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + val * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) res[i][i] = 1;

        while (exp) {
            if (exp & 1) res = multiply(res, base);

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        int S = 2 * m;

        Matrix T(S, vector<long long>(S, 0));

        // Up states: 0 ... m-1
        // Down states: m ... 2m-1

        for (int x = 0; x < m; x++) {

            // newUp[x] = sum down[y] (y < x)
            for (int y = 0; y < x; y++) {
                T[x][m + y] = 1;
            }

            // newDown[x] = sum up[y] (y > x)
            for (int y = x + 1; y < m; y++) {
                T[m + x][y] = 1;
            }
        }

        vector<long long> state(S, 0);

        // Length = 2 initialization
        for (int v = 0; v < m; v++) {
            state[v] = v;            // up[v]
            state[m + v] = m - 1 - v; // down[v]
        }

        Matrix P = power(T, n - 2);

        vector<long long> finalState(S, 0);

        for (int i = 0; i < S; i++) {
            long long cur = 0;

            for (int j = 0; j < S; j++) {
                cur = (cur + P[i][j] * state[j]) % MOD;
            }

            finalState[i] = cur;
        }

        long long ans = 0;

        for (long long x : finalState) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};