class Solution {
    static const int mod = 1e9+7;
    static const int log = 17;

    vector<int> depth;
    vector<vector<int>> up;
    vector<vector<int>> adj;

    long long modpow(long long base, long long exp){
        long long res = 1;
        while(exp){
            if(exp & 1){
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            exp >>=1;
        }
        return res;
    }

    void dfs(int node, int parent){
        up[node][0] = parent;

        for(int j=1; j<log; j++){
            if(up[node][j-1] == -1){
                up[node][j] = -1;
            }else{
                up[node][j] = up[up[node][j-1]][j-1];
            }
        }

        for(int next: adj[node]){
            if(next == parent){
                continue;
            }
            depth[next] = depth[node]+1;
            dfs(next, node);
        }
    }

    int lca(int u, int v){
        if(depth[u] < depth[v]){
            swap(u, v);
        }
        int diff = depth[u]-depth[v];

        for(int j = log-1; j>=0; j--){
            if(diff & (1 << j)){
                u = up[u][j];
            }
        }
        if(u == v){
            return u;
        }

        for(int j=log-1; j>=0; j--){
            if(up[u][j] != up[v][j]){
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        
        adj.assign(n+1, {});
        depth.assign(n+1, 0);
        up.assign(n+1, vector<int>(log, -1));

        for(auto &e: edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // root = 1 :)
        dfs(1, -1);
        vector<int> ans;

        for(auto &q: queries){
            int u = q[0];
            int v = q[1];

            int ancestor = lca(u, v);
            int dist = depth[u] + depth[v] - 2*depth[ancestor];

            if(dist == 0){
                ans.push_back(0);
            }else{
                ans.push_back((int)modpow(2, dist-1));
            }
        }
        return ans;
    }
};
