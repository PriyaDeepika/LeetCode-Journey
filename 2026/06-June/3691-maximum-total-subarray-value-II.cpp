class Solution {
public:
    vector<vector<int>> stmax, stmin;
    vector<int> lg;
        
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        lg.resize(n+1);
        for(int i=2; i<=n; i++){
            lg[i] = lg[i/2]+1;
        }
        int x = lg[n]+1;
        stmax.assign(x, vector<int>(n));
        stmin.assign(x, vector<int>(n));

        for(int i=0; i<n; i++){
            stmax[0][i] = nums[i];
            stmin[0][i] = nums[i];
        }
        for(int j=1; j <x; j++){
            for(int i=0; i+(1<<j)<=n; i++){
                stmax[j][i] = max(
                    stmax[j-1][i],
                    stmax[j-1][i+(1<<(j-1))]
                );

                stmin[j][i] = min(stmin[j-1][i],stmin[j-1][i+(1<<(j-1))]);
            }
        }

        auto getvalue = [&](int l, int r) -> long long {
            int len = r-l+1;
            int j = lg[len];

            int mx = max(
                stmax[j][l], stmax[j][r-(1<<j)+1]
            );
            int mn = min(
                stmin[j][l], stmin[j][r-(1<<j)+1]
            );

            return 1LL*mx-mn;
        };
        priority_queue<array<long long, 3>> pq;

        for(int l = 0; l<n; l++){
            pq.push({getvalue(l, n-1), l, n-1});
        }

        long long ans = 0;

        while(k--){
            auto [val, l, r] = pq.top();
            pq.pop();
            ans += val;
            if(r>l){
                pq.push({getvalue(l, r-1), l, r-1});
            }
        }
        return ans;
    }
};
