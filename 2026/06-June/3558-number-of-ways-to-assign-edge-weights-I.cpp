class Solution {
public:
    int mod = 1e9+7;
    long long modpow(long long a, long long depth){
        long long res = 1;
        while(depth){
            if(depth & 1){
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            depth >>= 1;
        }
        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n+1);
        for(auto &e: edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<pair<int, int>> q;
        vector<int> vis(n+1, 0);
        q.push({1, 0});
        vis[1] = 1;
        int maxdepth = 0;

        while(!q.empty()){
            auto [node, depth] = q.front();
            q.pop();

            maxdepth = max(maxdepth, depth);

            for(int next: adj[node]){
                if(!vis[next]){
                    vis[next] = 1;
                    q.push({next, depth+1});
                }
            }
        }
        return modpow(2, maxdepth-1);
    }
};
