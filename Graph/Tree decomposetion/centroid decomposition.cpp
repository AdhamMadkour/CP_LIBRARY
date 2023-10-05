int sub[N], parent[N];
 
int dfs1(int node, int par) {
    sub[node] = 1;
    for (auto child: adj[node]) {
        if (child != par)
            sub[node] += dfs1(child, node);
    }
    return sub[node];
}
 
int dfs2(int node, int par, int n) {
    for (auto child: adj[node]) {
        if (child != par && sub[child] > n / 2) {
            return dfs2(child, node, n);
        }
    }
    return node;
}
 
void decompose(int node, int par) {
    int subTree = dfs1(node, -1);
    int centroid = dfs2(node, par, subTree);
    parent[centroid] = par;
    for (auto child: adj[centroid]) {
        adj[child].erase(centroid);
        decompose(child, centroid);
    }
}
 
int ads[N];
 
void update(int node) {
    int anc = node;
    while (~anc) {
        ads[anc] = min(ads[anc], dist(node, anc));
        anc = parent[anc];
    }
}
 
int query(int node) {
    int anc = node;
    int ans = 1e9;
    while (~anc) {
        ans = min(ans, ads[anc] + dist(node, anc));
        anc = parent[anc];
    }
    return ans;
}
 