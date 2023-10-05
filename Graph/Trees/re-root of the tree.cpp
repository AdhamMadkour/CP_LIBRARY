#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define int ll
#define Fast_IO ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> adj[N];
int dp[N], sub[N];

void dfs(int node, int par) {
    sub[node] = 1;
    dp[node] = 0;
    for (auto child: adj[node]) {
        if (child != par) {
            dfs(child, node);
            sub[node] += sub[child];
            dp[node] += dp[child];
        }
    }
    dp[node] += sub[node];
    return;
}

int ans = 0;

void dfs1(int node, int par) {
    ans = max(ans, dp[node]);
    for (auto child: adj[node]) {
        if (child != par) {
            // deattach the current node to reroot the child node by subtract the values of the child as a child by assuming removing
            // the edge between them and making the child as a root an all of that before moving to the next node and after that
            // we are rolling back all the changes
            dp[node] -= dp[child];
            dp[node] -= sub[child];
            sub[node] -= sub[child];
            // reRoot
            sub[child] += sub[node];
            dp[child] += sub[node];
            dp[child] += dp[node];

            dfs1(child, node);
            // rollout
            dp[child] -= dp[node];
            dp[child] -= sub[node];
            sub[child] -= sub[node];

            sub[node] += sub[child];
            dp[node] += sub[child];
            dp[node] += dp[child];
        }
    }
    return;
}

void blow_it() {
    int n;
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    dfs1(1, 0);
    cout << ans << endl;
}

/*
    5
    1 2
    1 3
    2 4
    2 5
    output = 14
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