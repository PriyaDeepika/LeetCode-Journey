class Solution {
public:
    static constexpr int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<int> up(m, 1);
        vector<int> down(m, 1);

        vector<int> prefUp(m + 1);
        vector<int> prefDown(m + 1);

        for (int len = 1; len < n; len++) {

            prefUp[0] = prefDown[0] = 0;

            for (int i = 0; i < m; i++) {
                prefUp[i + 1] = (prefUp[i] + up[i]) % MOD;
                prefDown[i + 1] = (prefDown[i] + down[i]) % MOD;
            }

            vector<int> newUp(m);
            vector<int> newDown(m);

            for (int j = 0; j < m; j++) {
                newUp[j] = prefDown[j];
                newDown[j] = (prefUp[m] - prefUp[j + 1] + MOD) % MOD;
            }
            up = move(newUp);
            down = move(newDown);
        }

        long long ans = 0;

        for (int x : up)
            ans = (ans + x) % MOD;

        for (int x : down)
            ans = (ans + x) % MOD;

        return (int)ans;
    }
};
