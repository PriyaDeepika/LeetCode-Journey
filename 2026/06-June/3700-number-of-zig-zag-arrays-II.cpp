class Solution {
public:
    static constexpr long long MOD = 1000000007;
    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        int p = B.size();
        int m = B[0].size();

        Matrix C(n, vector<long long>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < p; k++) {
                if (A[i][k] == 0) continue;
                long long val = A[i][k];
                for (int j = 0; j < m; j++) {
                    C[i][j] = (C[i][j] + val * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int sz = base.size();
        Matrix result(sz, vector<long long>(sz, 0));

        for (int i = 0; i < sz; i++) result[i][i] = 1;

        while (exp > 0) {
            if (exp & 1) result = multiply(result, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return result;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int sz = 2 * m;

        Matrix T(sz, vector<long long>(sz, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                T[j + m][i] = 1;
            }

            for (int j = i + 1; j < m; j++) {
                T[j][i + m] = 1;
            }
        }

        Matrix dp(1, vector<long long>(sz, 1));
        Matrix Texp = power(T, n - 1);
        Matrix finalDP = multiply(dp, Texp);

        long long ans = 0;
        for (int i = 0; i < sz; i++) {
            ans = (ans + finalDP[0][i]) % MOD;
        }

        return (int)ans;
    }
};
