#define LOG 18  // log2(100000) ≈ 17, using 18 for safety
#define N 200005

vector<int> adj[N];
int depth[N];
int parent[N][LOG];

// DFS to calculate depth and binary lifting table
void dfs(int node, int par) {
    parent[node][0] = par;
    for (int i = 1; i < LOG; i++) {
        if (parent[node][i-1] != -1) {
            parent[node][i] = parent[parent[node][i-1]][i-1];
        }
    }
    for (int neighbor : adj[node]) {
        if (neighbor != par) {
            depth[neighbor] = depth[node] + 1;
            dfs(neighbor, node);
        }
    }
}

// Binary Lifting to find LCA
int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    // Bring u and v to the same depth
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = parent[u][i];
        }
    }

    if (u == v) return u;

    // Lift both nodes up until we find the LCA
    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

// Find the k-th ancestor of a node
int get_kth_ancestor(int node, int k) {
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) {
            node = parent[node][i];
        }
    }
    return node;
}
