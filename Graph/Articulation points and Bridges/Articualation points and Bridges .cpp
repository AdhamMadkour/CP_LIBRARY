#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define int ll
#define Fast_IO ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
const int mod = 1e9 + 7;
const int N = 1e5 + 10;

vector<int> adj[N];
vector<int> low, dis, vis;
int timer = 1;
vector<pair<int, int>> bridges;
set<int> articulation_points;

int dfs(int node, int par) {
    vis[node] = 1;
    // time for both the  lower time and the discovery time is equal to the current discoverd time 
    dis[node] = low[node] = timer++;
    int numOfChild = 0;
    for (auto child: adj[node]) {
        if (!vis[child]) {
            // first the dfs to calculate the low and discovery time for each node
            dfs(child, node);
            numOfChild++;
            low[node] = min(low[child], low[node]);
            if (low[child] > dis[node]) {
                bridges.emplace_back(node, child);
            }
            if (par != 0 && low[child] >= dis[node]) {
                articulation_points.insert(node);
            }

        } else if (child != par) {
            // in this case their is a backedge so we are going to need a get the lowest time in that node 
            low[node] = min(low[node], dis[child]);
        }
    }
    if (par == 0 && numOfChild > 1) {
        articulation_points.insert(node);
    }
    return 1;
}

void blow_it() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        adj[i].clear();
    vis = low = dis = vector<int>(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << bridges.size() - 1 << endl;
}

void preprocess() {

}

int32_t main() {
    Fast_IO;
    //freopen("race.in", "r", stdin);
    //freopen("abdo.txt", "w", stdout);
    int t = 1;
    cin >> t;
    preprocess();
    while (t--) {
        blow_it();
    }
    return 0;
}