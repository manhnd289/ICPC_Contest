#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    DSU(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u != root_v) {
            if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
            } else if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
            } else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    vector<string> results(N, "NO");
    DSU dsu(N + 1);
    vector<bool> active(N + 1, false);
    int components = 0;

    for (int i = N - 1; i >= 0; --i) {
        int node = P[i];
        active[node] = true;
        components++;

        for (int neighbor : adj[node]) {
            if (active[neighbor]) {
                if (dsu.find(node) != dsu.find(neighbor)) {
                    dsu.unite(node, neighbor);
                    components--;
                }
            }
        }

        if (components == 1) {
            results[i] = "YES";
        }
    }

    for (int i = 0; i < N; ++i) { // In ra kết quả cho tất cả trừ bước cuối cùng
        cout << results[i] << '\n';
    }

    return 0;
}
