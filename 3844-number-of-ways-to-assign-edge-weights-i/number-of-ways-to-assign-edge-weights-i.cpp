class Solution {
public:
    long long modpow(long long a, long long b, long long m) {
        long long res = 1;
        a %= m;
        while (b > 0) {
            if (b & 1)
                res = (res * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return res;
    }

    long long height(unordered_map<long long, vector<long long>>& adj, long long node, long long parent) {
        long long maxi = 0;

        for (long long j = 0; j < adj[node].size(); j++) {
            long long neigh = adj[node][j];
            if (neigh == parent)
                continue;
            maxi = max(maxi, 1 + (height(adj, neigh, node)));
        }
        return maxi;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<long long, vector<long long>> adj;
        for (auto& e : edges) {
            long long u = e[0];
            long long v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        long long d = height(adj, 1, -1);
        return modpow(2, d - 1, 1000000007);
    }
};