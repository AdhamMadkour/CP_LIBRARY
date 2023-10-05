#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define int ll
#define Fast_IO ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
vector<int> adj[N];
vector<int> tadj[N];
int vis[N], col[N];
vector<int> topo;

// first we use the topo sort to traverse from the sink nodes and traverse them in the transposed graph 
void dfs(int node) {
    vis[node] = true;
    for (auto child: adj[node]) {
        if (!vis[child])dfs(child);
    }
    topo.push_back(node);
    return;
}

map<int, vector<int>> cp;

// dfs in each component in the transposed graph 
void dfs2(int node, int comp) {
    vis[node] = true;
    col[node] = comp;
    cp[comp].push_back(node);
    for (auto child: tadj[node]) {
        if (!vis[child])dfs2(child, comp);
    }
    return;
}

void blow_it() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        tadj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i])dfs(i);
    }
    memset(vis, 0, sizeof(vis));
    reverse(topo.begin(), topo.end());
    int comp = 1;
    for (auto i: topo) {
        if (!vis[i])dfs2(i, comp++);
    }
    cout << comp - 1 << endl;
}

/*
9 11
1 3
3 2
2 1
3 4
4 5
5 6
6 4
8 2
8 7
7 9
9 8
----------
3
*/
void preprocess() {

}

int32_t main() {
    Fast_IO;
    //freopen("race.in", "r", stdin);
    //freopen("abdo.txt", "w", stdout);
    int t = 1;
    //cin >> t;
    preprocess();
    while (t--) {
        blow_it();
    }
    return 0;
}