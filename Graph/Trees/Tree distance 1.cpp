int sub[N], ans[N];
vector<int> adj[N];

void dfs(int node, int par) {
    for (auto child: adj[node])
        if (child != par) {
            dfs(child, node);
            sub[node] = max(sub[node], sub[child] + 1);
        }
}

void dfs2(int node, int par, int parent_dist) {
    int mx1 = -1, mx2 = -1;
    for (auto child: adj[node]) {
        if (child != par) {
            if (sub[child] > mx1) mx2 = mx1, mx1 = sub[child];
            else if (sub[child] > mx2)mx2 = sub[child];
        }
    }
    for (auto child: adj[node]) {
        if (child != par) {
            int new_dist = parent_dist;
            if (sub[child] == mx1)
                new_dist = max(new_dist, mx2);
            else
                new_dist = max(new_dist, mx1);

            dfs2(child, node, new_dist + 1);
            ans[node] = max(ans[node], sub[child] + 1);
        }
    }
    ans[node] = max(ans[node], parent_dist + 1);
}
