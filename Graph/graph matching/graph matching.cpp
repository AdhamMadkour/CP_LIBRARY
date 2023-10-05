/*
*  Author:  ___  ____  __     ____  ____  _
*          /███\ ████ /██\   /████| ████  █
*          █   █ █  █ █  █   █      █  █  █
*          █████ ███  █  █   █ |███ ███   █
*          █   █ █  █ █  █   █   █  █  █  █
*          █   █ ████ \██/   \███/  ████  ████|
*/
#include<bits/stdc++.h>

using namespace std;
#define Fast_IO ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int dx4[] = {-1, 0, 0, 1};
int dy4[] = {0, -1, 1, 0};
#define ll long long
#define ull unsigned long long
const int mod = (int) 1e9 + 7;
const double pi = acos(-1);
const int N = 1e5 + 2;
const ll oo = LONG_LONG_MAX;
vector<int> adj[N];
int match[10005];
bool vis[10005];

bool dfs(int node) {
    for (auto v:adj[node]) {
        if (!vis[v]) {
            vis[v] = true;
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = node;
                return true;
            }
        }
    }
    return false;
}

int main() {
    Fast_IO;
    /*freopen ("input.in","r",stdin);
    freopen ("output.out","w",stdout);*/
    int t;
    cin >> t;
    while (t--) {
        int m, n, sum = 0, x, y;
        cin >> m >> n;
        for (int i = 0; i < m; i++) {
            adj[i].resize(2);
            cin >> adj[i][0] >> adj[i][1];
        }
        memset(match, -1, sizeof(match));
        for (int i = 0; i < m; i++) {
            memset(vis, 0, sizeof(vis));
            if (dfs(i)) sum++;
            else break;
        }
        if (sum == m) cout << "successful hashing";
        else cout << "rehash necessary";
        cout << endl;

    }
    return 0;
}